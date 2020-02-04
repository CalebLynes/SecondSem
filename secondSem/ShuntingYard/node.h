//node.h
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

//Node Header File
class Node {
 public:
  //constructor + descructor
  Node(char c, Node* n);
  ~Node();
  //contains a character and a left/right node
  char data;
  Node* left;
  Node* right;
};

#endif
