//main.cpp
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h> //floor

using namespace std;

void maxHeapify(int (&A)[100], int i, int size, int &count);
void printHeap(int (&A)[100], int size);
void printGivenLevel(int (&A)[100], int root, int level, int size);

//---Main---
int main() {
  
  int size = 0;
  char input[] = {"7 6 5 4 3 2 1"};
  //amount of elements in array
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  size++;
  cout << "Size: " << size << endl;
  //empty heap
  int heap[100];

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
  int count = 1;
  while (count > 0) {
    cout << "RESTART" << endl;
    count = 0;
    for (int i = 0; i < size; i++) {
      maxHeapify(heap, i, size, count);
    }
  }
  cout << "DONE" << endl;
  cout << endl;
  for (int i = 0; i < size; i++) {
    cout << heap[i] << endl;
  }
  cout << endl;
  printHeap(heap, size);
  
  return 0;
}

void maxHeapify(int (&A)[100], int i, int size, int &count) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    cout << "i: " << A[largest] << ",  ";
    cout << "left: " << A[left] << ",  ";
    cout << "right: " << A[right] << endl;
    
    if (A[left] > A[largest] && left <= size) {
        largest = left;
    }
    if (A[right] > A[largest] && right <= size) {
        largest = right;
    }
    if (largest != i) {
        cout << "Swap " << A[i] << " and " << A[largest] << endl;
        //a change was made
        //swap largest and i
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        count++;
        maxHeapify(A, largest, size, count);
    }
}

void printHeap(int (&A)[100], int size) {
  cout << "Size: " << size << endl;
  int levels = floor(1 + log2(size));
  cout << "levels: " << levels << endl;
  
  int nodesBeforeLast = pow(2, levels-1) - 1;
  cout << "Nodes before last: " << nodesBeforeLast << endl;
  int lastLevelNodes = size - nodesBeforeLast;
  cout << "Nodes on last level: " << lastLevelNodes << endl;

  for (int i = 1; i <= levels; i++) {
    printGivenLevel(A, A[0], i, size);
  }
}

void printGivenLevel(int (&A)[100], int root, int level, int size) {
  if (root == 0) {
    return;
  }
  if (level == 1) {
    cout << root << endl;
  }
  else if (level > 1) {
    //level is greater than 1
    
  }
}
