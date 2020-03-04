#include <iostream>
#include <cstring> //strlen
#include <stdlib.h> //atoi
#define BLACK 1
#define RED 2

using namespace std;

//Node struct
struct Node {
  int color; // 1 = black, 2 = red
  int data;
  Node* left = NULL;
  Node* right = NULL;
  Node* parent = NULL;
};

//function prototypes
void insert(Node* &head, Node* &current, Node* &prev, Node* &n);
void print(Node* head, int space);
void balance(Node* &head, Node* &current);

//---------- M A I N ----------
int main() {
  Node* head = NULL;
  int size = 1;

  char input[] = {"6 3 4 2 8 7 5 9 1"};
  
  //find size
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  cout << "Size: " << size << endl;

  //add to int array
  int arr[100];
  int j = 0;
  char* a = strtok(input, " ");
  while (a != NULL) {
    int key = atoi(a);
    arr[j] = key;
    j++;
    a = strtok(NULL, " ");
  }

  //insert each number into tree
  for (int i = 0; i < size; i++) {
    Node* n = new Node;
    n->data = arr[i];
    insert(head, head, NULL, n);
  }
  
  print(head, 0);
  
  return 0;
}
//------ E N D   M A I N ------


//----- Insert -----
void insert(Node* &head, Node* &current, Node* &prev, Node* &n) {
  //Case 1: root is null
  if (head == NULL) {
    //tree is empty
    head = n;
    head->color = BLACK;
  }
  else {
    //tree is not empty
    if (current == NULL) {
      //current leaf is empty
      current = n;
      current->color = RED;
      current->parent = prev;

      //balance
      balance(head, current);

      }
    }
    else {
      //current is not empty
      if (n->data > current->data) {
	//recursively call on right
	insert(head, current->right, current, n);
      }
      if (n->data < current->data) {
	//recursively call on left
	insert(head, current->left, current, n);
      }
    }
  }
}

//----- Balance -----
void balance(Node* &head, Node* &current) {
  //Case 2: parent is black
  if (current->parent->color == BLACK) {
    //all done
  }
  else {
    //Case 3: Parent & Uncle are red
    if (current->parent->parent->left == current) {
      //currents parent is gp's left

      //check if parent and uncle are red
      if (current->parent->parent->right->color == RED) {

	//change parent and uncle to black
	current->parent->color = BLACK;
        current->parent->parent->right->color = BLACK;
	
        //change gp to red
	current->parent->parent->color = RED;
	
        //recursively call on grandparent
	balance(head, current->parent->parent);
      }
    }
    else if (current->parent->->parent->right == current) {
      //currents parent is gp's right

      //check if parent and uncle are red
      if (current->parent->parent->left->color == RED) {
	
      //change parent and uncle to black
	current->parent->color = BLACK;
	current->parent->parent->left->color = BLACK;
	
        //change gp to red
	current->parent->parent->color = RED;
	
        //recursively call on grandparent
	balance(head, current);
      }
    }
  }
}

//----- Print -----
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
  cout << head->data << "," << head->color << endl;

  //left child
  print(head->left, space);
}
