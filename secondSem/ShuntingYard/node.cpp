//node.cpp
#include <iostream>
#include "node.h"

using namespace std;

//Node CPP File

//constructor
Node::Node(char c, Node* n) {
    if (n != NULL) {
        data = n->data;
        left = n->left;
        right = n->right;
    }
    else {
        data = c;
    }
}

//destructor
Node::~Node() {
    left = NULL;
    right = NULL;
}
