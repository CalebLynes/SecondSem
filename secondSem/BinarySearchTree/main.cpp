#include <iostream>
#include <cstring>

using namespace std;

//Node struct
struct Node {
  int data;
  Node* left;
  Node* right;
};

//function prototypes
void add(Node* &head, int data);
void remove(Node* &head, int data);
void print(Node* head);

//--------MAIN--------
int main() {
  int size = 1;
  Node* head = NULL;

  //base input array
  char input[] = {"6 3 4 2 8 7 5 9 1"};

  //find size
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      size++;
    }
  }
  cout << "Size: " << size << endl;

  //add each item to tree
  for (int i = 0; i <= size; i++) {
    add(head, input[i]);
  }
  
  return 0;
}
//------END MAIN------

//---add
void add(Node* &head, int data) {
  if (head == NULL) {
    //tree is empty
    head = new Node;
    head.data = data;
  }
  else {
    //tree is not empty
    
  }
}

//---remove
void remove(Node* &head, int data) {
  
}

//---print
void print(Node* head) {
  
}
