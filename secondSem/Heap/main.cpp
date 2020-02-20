//main.cpp
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h> //floor
#include <fstream> //files

using namespace std;

/* Author: Caleb Lynes
 * Date: 2/19/20
 * Project: Take in input either via a text file or raw input and convert * to a max-heap. Take the heap and remove each element from it adding to * output in order of largest to smallest (since this is a max-heap). Be * able to print out the heap in tree form
 */


//function prototypes
void maxHeapify(int (&A)[201], int i, int size, int &count);
void printHeap(int (&A)[201], int root, int space, int i);

//---testing
//void getNodesAtLevel(int i, int current, int prev, int levels);
//343 87 904 132 654 64 66 23 475 999 303 404


//------------ MAIN ------------//
int main() {
  
  fstream newfile;

  //size = actual # of elements in given array of ints
  int size = 0;

  //---testing
  //char input[] = {"1 6 4 2 3 5"};

  char input[100000];
  
  //take in input of numbers or a file of numbers
  cout << "Take in  a) File  or  b) Normal input? (a or b) ";
  char answer[2];
  cin.get(answer, 2);
  cin.get();
  
  //Take in user input via File
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

  //Take in user input via Raw Input
  else if (answer[0] == 'b') {
    //take in raw input and assign it directly to base input array
    //-- ! Important ! --> This (lazy) method of taking in input relies on user inputing everything correctly
    cout << "Enter a series of numbers from 1-1000 separated by spaces (100 numbers max)" << endl;
    cin.get(input, 101);
    cin.get();

  }
  //failsafe for if user does not input 'a' or 'b'
  else {
    cout << "Invalid input" << endl;
    return 0;
  }
  
  //find amount of elements in input array
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  size++;
  cout << "Size: " << size << endl;

  //empty heap
  //needs 201 numbers to failproof out of bounds exceptions (considering 100 max numbers)
  int heap[201];
  
  //initialize heap to all 0s
  //this is important for printing heap later
  for (int k = 0; k < 201; k++) {
    heap[k] = 0;
  }

  //add each element to heap
  int j = 0;
  char* a = strtok(input, " ");
  while (a != NULL) {
    int key = atoi(a);
    heap[j] = key;
    j++;
    a = strtok(NULL, " ");
  }

  //max heapify each element (check if its own left and right is higher
  //than root) keeping track of a count. If count > 0, a change was made,
  //restart iteration. If count == 0, no further changes need to be made.
  cout << "Constructing max-heap..." << endl;
  int count = 1;
  while (count > 0) {
    //--used for testing--
    //cout << "RESTART" << endl;
    count = 0;
    for (int i = 0; i < size; i++) {
      maxHeapify(heap, i, size, count);
    }
  }
  cout << "DONE" << endl;
  cout << endl;

  //print out heap (will be inorder traversal format)
  cout << "Heap in inorder format: " << endl;
  for (int i = 0; i < size; i++) {
    cout << heap[i] << endl;
  }
  cout << endl;

  //print heap in tree form
  cout << "Heap in tree format: " << endl;
  printHeap(heap, heap[0], 0, 0);

  //remove each item in order from the heap. 
  //Continue removing until heap is empty.
  //Output should be from largest to smallest (max-heap).

  //------BLOCK OF RANDOM TEST STUFF------- 
  /*
  cout << endl << "Size: " << size << endl;
  int levels = floor(1 + log2(size));
  cout << "levels: " << levels << endl;
  int nodesBeforeLast = pow(2, levels-1) - 1;
  cout << "Nodes before last level: " << nodesBeforeLast << endl;
  int lastLevelNodes = size - nodesBeforeLast;
  cout << "Nodes on last level: " << lastLevelNodes << endl;

  //prints amount of nodes on each level
  cout << endl << "# of nodes on each level: " << endl;
  for (int i = 1; i <= levels; i++) {
    cout << "Level " << i << ": ";
    if (i == levels) {
      cout << lastLevelNodes << endl;
    }
    else {
      getNodesAtLevel(i, levels, 0, levels);
    }
  }
  */
  //------END OF TESTING BLOCK-------


  //Pop root node to ouput and put last node in its place. 
  //Then re-heapify until in order again.
  
  cout << "Removing all nodes from heap to output in order of value..." << endl;

  //n is to keep base amount of elements that is in our system while original size variable is being changed
  int n = size;
  
  //final output variable
  int output[100];
  
  for (int i = 0; i < n; i++) {
    //get last element
    int lastElement = heap[size-1];
    
    //add root to output
    output[i] = heap[0];
    
    //set root to last element
    heap[0] = lastElement;
    
    //decrease size of heap
    size = size - 1;

    //re-heapify new root
    int count = 1;
    while (count > 0) {
      count = 0;
      for (int i = 0; i < size; i++) {
        maxHeapify(heap, i, size, count);
      }
    }

  }
  cout << "DONE" << endl << endl;

  //print final output
  cout << "Final output: " << endl;
  for (int i = 0; i < n; i++) {
    cout << output[i] << "  ";
  }
  cout << endl;
  
  //print end of program size (mainly for testing but nice to know regardless)
  cout << "End size: " << size << endl;


  return 0;

}
//------------ END MAIN ------------//

/*
void getNodesAtLevel(int i, int current, int prev, int levels) {
  int nodes = pow(2, current-1);
  if (current == i) {
    cout << nodes << endl;
  }
  else {
    getNodesAtLevel(i, current-1, current, levels);
  }
}*/


//---Max Heapify
// A represents the heap, i represents the current largest index
//being evaluated, size represents the # of elements in the heap
//and count is a variable to check if the heap is done sorting
void maxHeapify(int (&A)[201], int i, int size, int &count) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    //--used for testing--
    //cout << "i: " << A[largest] << ",  ";
    //cout << "left: " << A[left] << ",  ";
    //cout << "right: " << A[right] << endl;

    //if current roots left is greater than current
    if (A[left] > A[largest] && left <= size) {
      //swap indexes
      largest = left;
    }
    
    //if current root's right is greater than current
    if (A[right] > A[largest] && right <= size) {
      //swap indexes
      largest = right;
    }
    if (largest != i) {
      //--used for testing--
      //cout << "Swap " << A[i] << " and " << A[largest] << endl;
      
      //IF we get here, a change was made in the indexes!
      //Swap largest and i
      int temp = A[i];
      A[i] = A[largest];
      A[largest] = temp;
      
      //adding to count reports that a change was made
      //and the heap may still need sorting
      count++;
      
      //call recursively using node index we just changed
      maxHeapify(A, largest, size, count);
    }
}

//---Print Heap
void printHeap(int (&A)[201], int root, int space, int index) {
  
  //base case
  if (root == 0) {
    return;
  }
  
  //increase indentation
  space += 10;

  //right child
  printHeap(A, A[2*index+2], space, 2*index+2);

  //print current node after indent
  cout << endl;
  for (int j = 10; j < space; j++) {
    cout << " ";
  }
  cout << root << "\n";

  //left child
  printHeap(A, A[2*index+1], space, 2*index+1);
}
