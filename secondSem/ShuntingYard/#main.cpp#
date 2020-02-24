//main.cpp
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

/* Author: Caleb Lynes
 * Date: 2-3-2020
 * Shunting Yard Algorithm - Program takes in a  
 * mathematical expression and translates it to postfix  
 * putting the now postfix notated expression into a 
 * queue. The queue is then used to construct a Binary 
 * Expression tree. The user is then prompted to either 
 * translate that tree into infix, postfix, or prefix 
 * notation.
 */

//Node struct used for creating both stacks (initial stack
//and tree stack) and the queue
struct node {
  char data;
  node* next = NULL;
  Node* node = NULL;
  //node ^^ is used for the Expression Tree stack only.
};


//function prototypes
void push(node* &top, node* &newnode);
node* pop(node* &top);
//peek was never used because pop() returns the node being popped.
char peek(node* top);
void addOpPostfix(node* &top, char c, node* &tail, node* &head);
void enqueue(node* &tail, node* &head, char c);
node* dequeue(node* &head);
void printQueue(node* head);
void addOpTree(node* &top, node* &head);
void infix(Node* tree);
void postfix(Node* tree);
void prefix(Node* tree);

//--------------------   M A I N   ------------------
int main() {
    //testing expressions:
    //(4+(6-7)*3)^2
    //4+2-1
    //(2*(2+(4-5)/4)*7^2)/3^4

    //stack and queue initial nodes
    node* stacktop = NULL;
    node* queuehead = NULL;
    node* queuetail = NULL;
    node* treetop = NULL;
    
    //ask user to input a mathematical expression
    char input[100];
    cout << "Enter a mathematical expression: ";
    cin.get(input, 100);
    cin.get();
    //char input[] = {"(2*(2+(4-5)/4)*7^2)/3^4"}; //(used for testing)
    //print user's input to console
    cout << "Input: " << input << endl;
    
    
    //Go through input and translate to postfix
    for (int i = 0; i < strlen(input); i++) {
        
        char c = input[i];
        switch (c) {
            //if its an operand (integer)
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                //add to queue
                enqueue(queuetail, queuehead, c);
                break;
            //if its an operator
            case '+': case '-': case '*': case '/': case '^': case '(': case ')':
                //determine what happens in the stack and queue and add/pop from stack accordingly
                addOpPostfix(stacktop, c, queuetail, queuehead);
                break;
            //ignore spaces
            case ' ':
                break;
            default:
                cout << "Invalid input" << endl;
        }
    }
  
    //input is now completely gone through and sorted into queue and stack using shunting yard algorithm
    //add the rest of the stack to the queue
    while (stacktop != NULL) {
        enqueue(queuetail, queuehead, pop(stacktop)->data);
    }
    //queue now has user's input as postfix notation
  
    //print Postfix to console
    cout << "Postfix: ";
    printQueue(queuehead);
    
    //---Build Binary Expression Tree---
    cout << "Building Tree..." << endl;
    //go through queue
    while (queuehead != NULL) {
        switch (queuehead->data) {
            case '+': case '-': case '/': case '*': case '^':
                //if item in queue is an operator
                //pop the two top items from the tree stack and make it its left and right.
                //Then push itself to stack.
                addOpTree(treetop, queuehead);
                break;
            default:
                //if item in queue is an operand
                //push to tree stack
                node* n = new node;
                node* temp = dequeue(queuehead);
                n->node = new Node(temp->data, temp->node);
                push(treetop, n);
        }
    }
    //testing for infix, postfix, and prefix translation algorithms
    /*
    cout << "Infix: ";
    infix(treetop->node);
    cout << endl;
    cout << "Postfix: ";
    postfix(treetop->node);
    cout << endl;
    cout << "Prefix: ";
    prefix(treetop->node);
    cout << endl;
    */

    cout << "Translate to Infix, Postfix, or Prefix?" << endl;
    //take in user input (making sure its valid) and pring out the specified notation
    char choice[8];
    while (true) {
        cin.get(choice, 8);
        cin.get();
        for (int i = 0; i < strlen(choice); i++) {
            choice[i] = tolower(choice[i]);
        }
        if (strcmp(choice, "infix")==0) {
            infix(treetop->node);
            break;
        }
        else if (strcmp(choice, "postfix")==0) {
            postfix(treetop->node);
            break;
        }
        else if (strcmp(choice, "prefix")==0) {
            prefix(treetop->node);
            break;
        }
        else {
            cout << "Invalid input" << endl;
        }
    }
    
    //end program
    return 0;
}
//----------------   E N D   M A I N   -----------------

//Infix Algorithm
//Translate expression tree to Infix notation
void infix(Node* tree) {
    //if subtree exists
    if (tree != NULL) {
        //if token is an operator, print parenthesis (only for infix notation)
        if (tree->data == '+' 
        || tree->data == '-' 
        || tree->data == '*' 
        || tree->data == '/' 
        || tree->data == '^') {
            cout << "(";
        }
        //call infix for left subtree, print token, then finally call infix for right subtree
        infix(tree->left);
        cout << tree->data;
        infix(tree->right);
        
        if (tree->data == '+' 
        || tree->data == '-' 
        || tree->data == '*' 
        || tree->data == '/' 
        || tree->data == '^') {
            cout << ")";
        }
    }
}

//Postfix Algorithm
//Translate expression tree to Postfix notation
void postfix(Node* tree) {
    //if subtree exists
    if (tree != NULL) {
        //call postfix on left subtree, then right subtree, then print token
        postfix(tree->left);
        postfix(tree->right);
        cout << tree->data;
    }
}

//Prefix Algorithm
//Translate expression tree to Prefix notation
void prefix(Node* tree) {
    //if subtree exists
    if (tree != NULL) {
        //print token, then call prefix on left subtree, then right subtree
        cout << tree->data;
        prefix(tree->left);
        prefix(tree->right);
    }
}

//---- Add Operator to Expression Tree ----
void addOpTree(node* &top, node* &head) {
    //push new node to stack popping top two items from it onto its left and right subtrees
    node* n = new node;
    node* temp = dequeue(head);
    n->node = new Node(temp->data, temp->node);
    node* temp2 = pop(top);
    n->node->right = new Node(temp2->data, temp2->node);
    //if statement is in case the branch will only have one subtree 
    //(usually only happens if there is a negative)
    if (top != NULL) {
        node* temp3 = pop(top);
        n->node->left = new Node(temp3->data, temp3->node);
    }
    push(top, n);
}


//----------Stack Push--------------
void push(node* &top, node* &newnode) {
    if (top == NULL) {
        //stack is empty
        top = newnode;
    }
    else {
        //stack is not empty
        node* temp = top;
        top = newnode;
        top->next = temp;
    }
}

//----------Stack Pop---------------
node* pop(node* &top) {
  if (top->next == NULL) {
      //only one thing in stack
      node* temp = top;
      top = NULL;
      return temp;
  }
  else {
      //more than one thing in stack
      node* temp = top;
      top = top->next;
      if (temp->next != NULL) {
        temp->next = NULL;
      }
      return temp;
  }
}

//----------Stack Peek--------------
//returns tops token (data)
char peek(node* top) {
  return top->data;
}

//----------Enqueue (queue push)--------------
void enqueue(node* &tail, node* &head, char c) {
    node* newnode = new node;
    newnode->data = c;
    if (tail == NULL) {
        //queue is empty
        tail = newnode;
        head = newnode;
    }
    else {
        //queue is not empty
        if (head->next == NULL) {
            //only one thing in queue
            tail = newnode;
            head->next = tail;
        }
        else {
            //more than one thing in queue
            node* temp = tail;
            tail = newnode;
            temp->next = tail;
        }
    }
}

//----------Dequeue (queue pop)---------------
node* dequeue(node* &head) {
    if (head->next == NULL) {
        //only one thing in queue
        node* temp = head;
        head = NULL;
        return temp;
    }
    else {
        //more than one thing in queue
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        return temp;
    }
}

//----------Print Queue-----------
void printQueue(node* head) {
    node* current = head;
    while (current != NULL) {
        cout << current->data;
        current = current->next;
    }
    cout << endl;
}

//----------Add Operator Postfix-----------------
void addOpPostfix(node* &top, char c, node* &tail, node* &head) {
    //  +  or  -
    if (c == '+' || c == '-') {
        if (top == NULL) {
            //stack is empty
            node* n = new node;
            n->data = c;
            push(top, n);
        }
        else {
            //stack is not empty
            while (top != NULL) {
                if (top->data == '(') {
                    break;
                }
                char ch = pop(top)->data;
                enqueue(tail, head, ch);
            }
            node* n = new node;
            n->data = c;
            push(top, n);
        }
    }
    //   *  or  /
    if (c == '*' || c == '/') {
        if (top == NULL) {
            //stack is empty
            node* n = new node;
            n->data = c;
            push(top, n);
        }
        else {
            //stack is not empty
            if (top->data == '/' || top->data == '*' || top->data == '^') {
                //need to pop things to queue
                while (top != NULL) {
                    if (top->data == '(' || top->data == '+' || top->data == '-') {
                        break;
                    }
                    char ch = pop(top)->data;
                    enqueue(tail, head, ch);
                }
            }
            node* n = new node;
            n->data = c;
            push(top, n);
        }
    }
    //   ^
    if (c == '^') {
        //highest level op, can just add right to stack
        node* n = new node;
        n->data = c;
        push(top, n);
    }
    //   )
    if (c == ')') {
        //pop everything onto queue until it finds its open parenthesis
        while (top->data != '(') {
            char ch = pop(top)->data;
            enqueue(tail, head, ch);
        }
        delete pop(top);
    }
    //   (
    if (c == '(') {
        //can just go right to stack
        node* n = new node;
        n->data = c;
        push(top, n);
    }
}
