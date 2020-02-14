//main.cpp
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h> //floor
#include <fstream> //files

using namespace std;

//function prototypes
void maxHeapify(int (&A)[200], int i, int size, int &count);
void printHeap(int (&A)[200], int root, int space, int i);

//------------ MAIN ------------//
int main() {

  fstream newfile;
  //size = actual # of elements in given array of ints
  int size = 0;
  //char input[] = {"343 87 904 132 654 64 66 23 475 999 303 404"};
  char input[100000];
  
  //take in input of numbers or a file of numbers
  cout << "Take in  a) File  or  b) Normal input? (a or b) ";
  char answer[2];
  cin.get(answer, 2);
  cin.get();
  if (answer[0] == 'a') {
    //File
    cout << "Enter file name (including .txt): ";
    char filename[50];
    cin.get(filename, 50);
    cin.get();
    newfile.open(filename);
    if (newfile.is_open()) {
      int n = 0;
      while (!newfile.eof()) {
	myfile.get(input[n]);
	n++;
      }
    }
  }
  else if (answer[0] == 'b') {
    //Normal input
    
  }
  else {
    cout << "Invalid input" << endl;
    return 0;
  }

  
  //find size
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  size++;
  cout << "Size: " << size << endl;

  //empty heap
  int heap[200];
  
  //initialize heap to all 0s
  //this is important for printing heap later
  for (int k = 0; k < 100; k++) {
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
  
  return 0;

}
//------------ END MAIN ------------//


//---Max Heapify
void maxHeapify(int (&A)[200], int i, int size, int &count) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    //--used for testing--
    //cout << "i: " << A[largest] << ",  ";
    //cout << "left: " << A[left] << ",  ";
    //cout << "right: " << A[right] << endl;

    //if current roots left is greater than itself
    if (A[left] > A[largest] && left <= size) {
      //swap indexes
      largest = left;
    }
    
    //if current root's right is greater than itself
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
void printHeap(int (&A)[200], int root, int space, int index) {
  
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
