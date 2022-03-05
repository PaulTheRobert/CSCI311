// CSCI 311 - Spring 2022
// Node Class
// Author: Carter Tillquist

#ifndef NODE_H
#define NODE_H

class Node{
  public:
    int value;
    Node* left;
    Node* right;
    
    Node();
    Node(int);
    ~Node();
};

#endif