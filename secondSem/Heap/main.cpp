//main.cpp
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h> //floor

using namespace std;

void maxHeapify(int (&A)[100], int i, int size, int &count);
void printHeap(int (&A)[100], int size);

//---Main---
int main() {
  
  int size = 0;
  char input[] = {"10 12 56 98 403 290 71 6 546 89 299 743 34 92 4"};
  //amount of elements in array
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
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
    for (int i = 0; i <= size; i++) {
      maxHeapify(heap, i, size, count);
    }
  }
  cout << "DONE" << endl;
  cout << endl;
  for (int i = 0; i <= size; i++) {
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
  float levels = floor(1 + log2(size));
  cout << "levels: " << levels << endl;

  
}
