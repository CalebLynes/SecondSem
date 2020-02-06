//main.cpp
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;


//---Main---
int main() {
  
  int size = 0;
  char input[] = {"10 3 9 78 5 23 34 98 12 4 87"};
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  int array[size+1];

  int j = 0;
  char* a = strtok(input, " ");
  while (a != NULL) {
    int key = atoi(a);
    array[j] = key;
    j++;
    a = strtok(NULL, " ");
  }
  
  for (int i = 0; i <= size; i++) {
    cout << array[i] << endl;
  }
  
  return 0;
}
