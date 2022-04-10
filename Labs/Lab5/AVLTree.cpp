// CSCI 311 - Spring 2022
// Lab 5 Skeleton - AVLTree cpp
// Author: Carter Tillquist

#include<iostream>
#include <vector>
#include <limits.h>
#include "AVLTree.h"
using namespace std;

// Constructor
AVLTree::AVLTree(){
  // initialize the root as a new AVL node
  AVLNode* root = new AVLNode;
}
// getter for the root - returns the root for the AVL
AVLNode* AVLTree::getRoot(){
  return root;
}
// getter for the size of the AVL tree - returns the size of the AVL tree
int AVLTree::getSize(){
  return size;
}
// search for the value - calls the recursive search by passing the root and the val
AVLNode* AVLTree::search(int val){
  return search(root, val);
}
// search for the value in the tree
AVLNode* AVLTree::search(AVLNode* n, int val){
  // base case - the tree is empty
  if(n == nullptr){return nullptr;}
  // check for match
  if(n->value == val){return root;}
  // compare and search recursively 
  if(val < n->value){search (n->left, val);}
  if(val > n->value){search (n->right, val);}
  return nullptr;
}

// return the minimum by calling the recursive version
AVLNode* AVLTree::minimum(){
  if(root == nullptr){return root;}
  minimum(root);
}

// return the minimum up the node recursively
AVLNode* AVLTree::minimum(AVLNode* n){
  if(n!=nullptr){
    return minimum(n->left);
  }
}
// return the max by calling the recursive version
AVLNode* AVLTree::maximum(){
  if(root == nullptr){return root;}
}
// return the max recursively 
AVLNode* AVLTree::maximum(AVLNode* n){
  if(n!=nullptr){
    return(minimum(n->right));
  }
}
// get the height of the node 
// do all of the checks here 
int getHeight(AVLNode* n){
  // empty node 
  if(n==nullptr){
    return -1;
  }
  // no childs
  else if(n->left == nullptr && n->right == nullptr){
    return 0;
  }
  // one childs
  else if((n->left == nullptr && n->right != nullptr) || (n->right == nullptr && n->left != nullptr)){
    return 1;
  }
  // two childs
  return 2;
}
// get the ballance factor of the node
// do all of the checks here 
int getBalanceFactor(AVLNode* n){
  if(n!=nullptr){
    return (getHeight(n->right) - getHeight(n->left));
  }
  return 0;
}
// insert a value into the AVL Tree
void AVLTree::insertValue(int val){
  root = insertValue(root, val);
}
// insert the value into the AVL tree in the correct place
AVLNode* AVLTree::insertValue(AVLNode* n, int val){
  // if the node is null, insert here
  if(n == nullptr){
    AVLNode* n = new AVLNode;
    n->value = val;
    size++;
    return n;
  }
  else if(val < n->value){
    n->left = insertValue(n->left, val);
  }else if(val > n->value){
    n->right = insertValue(n->right, val);
  }
  n->height = getHeight(n);
  n->balanceFactor = getBalanceFactor(n);

  return rebalance(n);
}

void AVLTree::deleteValue(int val){
}

AVLNode* AVLTree::deleteValue(AVLNode* n, int val){
  return nullptr;
}
// determine which type of rotation is required to reballance
AVLNode* AVLTree::rebalance(AVLNode* n){
if(n->balanceFactor == 2 || n->balanceFactor == -2){
  cout<<"Triggered reballance!"<<endl;
  if(n->balanceFactor == -2){
    if(getHeight(n->left->left) > getHeight(n->left->right)){
      cout<<"ROTATE RIGHT"<<endl;
      n = rotateRight(n);
      }
    else{
      cout<<"DOUBLE ROTATE LEFT/RIGHT"<<endl;
      n = rotateLeftRight(n);
      }
  }
  if(n->balanceFactor == 2){
    if(getHeight(n->right->right) > getHeight(n->right->left)){
      cout<<"ROTATE LEFT"<<endl;
      n = rotateLeft(n);
      }     
    else{
      cout<<"DOUBLE ROTATE RIGHT/LEFT";
      n = rotateRightLeft(n);
      }
  }
}
  return n;
}
// execute a lft rotation at node
AVLNode* AVLTree::rotateLeft(AVLNode* y){
  AVLNode* x = y->right;
  y->right = x->left;
    // update the height 
  y->height = getHeight(y);
  x->left = y;
  x->height = getHeight(x);
  // update balance factor
  y->balanceFactor = getBalanceFactor(y);
  return x;
}
// execute a right rotation at node
AVLNode* AVLTree::rotateRight(AVLNode* y){
  AVLNode* x = y->left;
  y->left = x->right;
  // update the height 
  y->height = getHeight(y);
  x->right = y;
  x->height = getHeight(x);
  // update balance factor
  y->balanceFactor = getBalanceFactor(y);
  return x;  
}
// execute a Left Right rotation at node
AVLNode* AVLTree::rotateLeftRight(AVLNode* y){
  // update the height 
  y->height = getHeight(y);
  // update balance factor
  y->balanceFactor = getBalanceFactor(y);
  // return x;
}
// execute a Right Left rotation at node
AVLNode* AVLTree::rotateRightLeft(AVLNode* y){
  // update the height 
  y->height = getHeight(y);
  // update balance factor
  y->balanceFactor = getBalanceFactor(y);
  // return x;
}

// add the values from the AVL tree into a vector with a pre order traversal
void AVLTree::preOrder(AVLNode* n, vector<AVLNode*> &order){
  // base case - the avl node is null
  if(n == nullptr){return;}
  order.push_back(n);
  preOrder(n->left, order);
  preOrder(n->right, order);
}
// add the values from the AVL tree into a vector with an inOrder traversal
void AVLTree::inOrder(AVLNode* n, vector<AVLNode*> &order){
  // base case, if the avl node is null
  if(n==nullptr){return;}
  inOrder(n->left, order);
  order.push_back(n);
  inOrder(n->right, order);
}

// add the values from the AVL tree into a vector with a post order traversal
void AVLTree::postOrder(AVLNode* n, vector<AVLNode*> &order){
  // base case if the avl node is null
  if(n==nullptr){return;}
  postOrder(n->left, order);
  postOrder(n->right, order);
  order.push_back(n);
}

