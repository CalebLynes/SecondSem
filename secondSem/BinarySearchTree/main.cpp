#include <iostream>
#include <cstring> // strlen
#include <fstream> // for file input
#include <stdlib.h> // atoi

using namespace std;

/*
Author: Caleb Lynes
Date: 2/24/20
Project: Binary Search Tree - Program takes in either a file of numbers separated by spaces or raw input from console of numbers and adds it to binary search tree. User is then able to add or remove from the tree, print the tree, or quit the program.
*/

//Node struct
struct Node {
  int data;
  Node* left = NULL;
  Node* right = NULL;
};

//function prototypes
void add(Node* &head, int data);
void remove(Node* &head, int data);
void print(Node* head, int space);

//--------MAIN--------
int main() {
  int size = 1;
  Node* head = NULL;

  fstream newfile;

  char input[100100];
  
  //take in input of numbers or a file of numbers
  cout << "Take in  a) File  or  b) Normal input? (a or b) ";
  char answer[2];
  cin.get(answer, 2);
  cin.get();
  
  //---Take in user input via File
  if (answer[0] == 'a') {
    //File
    cout << "Enter file name (including '.txt'): ";
    //get filename
    char filename[50];
    cin.get(filename, 50);
    cin.get();

    //open file and assign it to our newfile variable
    newfile.open(filename);
    if (newfile.is_open()) {
      //now that the file is open, 
      //take everything in the text document and assign it onto base input array
      int n = 0;
      while (!newfile.eof()) {
	      newfile.get(input[n]);
	      n++;
      }
    }
  }

  //---Take in user input via Raw Input
  else if (answer[0] == 'b') {
    //take in raw input and assign it directly to base input array
    //-- ! Important ! --> This (lazy) method of taking in input relies on user inputing everything correctly
    cout << "Enter a series of numbers from 1-1000 separated by spaces" << endl;
    cin.get(input, 101);
    cin.get();

  }

  //failsafe for if user does not input 'a' or 'b'
  else {
    cout << "Invalid input" << endl;
    return 0;
  }



  //base input array (testing)
  //char input[] = {"6 3 4 2 8 7 5 9 1"};

  //find size
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  cout << "Size: " << size << endl;

  //add to int array (for easier tree insertion)
  int arr[100];
  int j = 0;
  char* a = strtok(input, " ");
  while (a != NULL) {
    int key = atoi(a);
    arr[j] = key;
    j++;
    a = strtok(NULL, " ");
  }

  //add each item to tree
  for (int i = 0; i < size; i++) {
    add(head, arr[i]);
  }

  //print tree
  print(head, 0);
  cout << endl << endl;


  //At this point the program is ready to let the user add, remove, or print as much as they please

  while (true) {
    cout << "a) add  b) remove  c) print  d) quit   (a, b, or c)" << endl;
    char inp[2];
    cin.get(inp, 2);
    cin.get();

    // a case - Add
    if (inp[0] == 'a' || inp[0] == 'A') {
      cout << "Enter a number to add: ";
      int num;
      cin >> num;
      cin.get();
      add(head, num);
      cout << "Added." << endl;
    }
    // b case - Remove
    if (inp[0] == 'b' || inp[0] == 'B') {
      cout << "Enter a number to remove:";
      int num;
      cin >> num;
      cin.get();
      remove(head, num);
    }
    // c case - Print
    if (inp[0] == 'c' || inp[0] == 'C') {
      print(head, 0);
      cout << endl << endl;
    }
    // d case - Quit
    if (inp[0] == 'd' || inp[0] == 'D') {
      cout << "Terminating..." << endl;
      break;
    }
  }
  
  return 0;
}
//------END MAIN------

//---add
void add(Node* &head, int data) {
  if (head == NULL) {
    //tree is empty
    head = new Node;
    head->data = data;
  }
  else {
    //tree is not empty
    if (data > head->data) {
      //recursively recall on right
      add(head->right, data);
    }
    if (data < head->data) {
      //recursively recall on left
      add(head->left, data);
    }
  }
}

//---remove
void remove(Node* &head, int data) {
  if (head == NULL) {
    //tree is either empty or the node was not found
    cout << "Not found." << endl;
  }
  else {
    if (data == head->data) {
      //found a match!

      //LEAF Case
      if (head->left == NULL && head->right == NULL) {
        Node* temp = head;
        head = NULL;
        delete temp;
        cout << "Removed." << endl;
      }
      
      //Only has left child case
      else if (head->left != NULL && head->right == NULL) {
        //replace head with its left
        Node* temp = head;
        head = head->left;
        delete temp;
        cout << "Removed." << endl;
      }
      //Only has right child case
      else if (head->left == NULL && head->right != NULL) {
        //replace head with its right
        Node* temp = head;
        head = head->right;
        delete temp;
        cout << "Removed." << endl;
      }
      else {
        // TWO children
        //Nodes rights left child is null case
        if (head->right->left == NULL) {
          //nodes right is successor
          head->data = head->right->data;
          Node* temp = head->right;
          head->right = head->right->right;
          delete temp;
          cout << "Removed." << endl;
        }
        else {
          //right child has two children

          //find inorder successor (named current)
          Node* current = head->right;
          Node* prev = head;
          while (current->left != NULL) {
            prev = current;
            current = current->left;
          }

          //have currents parent adopt currents right
          prev->left = current->right;

          //copy data from current to our root node (head)
          head->data = current->data;

          //delete the successor
          delete current;
          cout << "Removed." << endl;
        }
      }
    }
    else {
      //no match, traverse recursively
      if (data > head->data) {
        //search right tree
        remove(head->right, data);
      }
      if (data < head->data) {
        //search left tree
        remove(head->left, data);
      }
    }
  }
}

//---print
void print(Node* head, int space) {
  //base case
  if (head == NULL) {
    return;
  }

  //increase indentation
  space += 10;

  //right child
  print(head->right, space);

  //print indent
  cout << endl;
  for (int i = 10; i < space; i++) {
    cout << " ";
  }
  //print current node
  cout << head->data << endl;

  //left child
  print(head->left, space);
}
