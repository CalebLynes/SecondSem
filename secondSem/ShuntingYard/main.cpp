//main.cpp
#include <iostream>
#include <cstring>

using namespace std;

struct node {
  char data;
  node* next = NULL;
};

void push(node* &head, node* &newnode);
node* pop(node* &head);
node* peek(node* head);

int main() {
  node* head = NULL;
  char input[] = {"(4+(6-7)*8)^2"};
  cout << input << endl;
  
  for (int i = 0; i < strlen(input); i++) {
    //create node
    node* n = new node;
    n->data = input[i];
    push(head, n);
  }
  
  
  return 0;
}

void push(node* &head, node* &newnode) {
  if (head == NULL) {
    //stack is empty
    head = newnode;
  }
  else {
    //stack is not empty
    node* temp = head;
    head = newnode;
    newnode->next = temp;
  }
}

node* pop(node* &head) {
  node* temp = head;
  head = head->next;
  temp->next = NULL;
  return temp;
}

node* peek(node* head) {
  return head;
}
