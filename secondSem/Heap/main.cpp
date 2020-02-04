//main.cpp
#include <iostream>
#include <cstring>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void push(Node* &head, Node* &newnode);
Node* pop(Node* &head);
Node* newNode(int data);

//---Main---
int main() {
  Node* head = NULL;

  char input[] = {"10 3 9 78 5 23"};
  char* a = strtok(input, " ");
  while (a != NULL) {
    push(head, newNode((int)(*a)));
    a = strtok(NULL, " ");
  }

  Node* current = head;
  while (current != NULL) {
    cout << current->data << endl;
    current = current->next;
  }
  
  
  return 0;
}

//---New Node---
Node* newNode(int data) {
  Node* n = new Node;
  n->data = data;
  return n;
}

//---Push---
void push(Node* &head, Node* &newnode) {
  if (head == NULL) {
    //heap is empty
    head = newnode;
  }
  else {
    //heap is not empty
    Node* temp = head;
    head = newnode;
    head->next = temp;
  }
}

//---Push---
Node* pop(Node* &head) {

  
}
