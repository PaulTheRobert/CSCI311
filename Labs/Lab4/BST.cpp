// CSCI 311 - Spring 2022
// Lab 4 - BST cpp
// Author: Paul Robert Davis

/*
  dev notes
   to run all tests 
   .././runTests a.out tests/

   to run a TEST
    .././runTests2 a.out tests/ 1
*/


#include<iostream>
#include <vector>
#include <limits.h>
#include "BST.h"
using namespace std;


BST::BST(){
  //initialize the values in the constructor
  Node* root = new Node();
  // root->value = 0;
  // root->left = nullptr;
  // root->right = nullptr;

}

BST::~BST(){}

// Lab 3
// find the value in the BST
Node* BST::search(int target){
  return search(root, target);
  
}
// recursive partner of the above function
Node* BST::search(Node* n, int target){
  if(n == nullptr){return nullptr;}
  if(n->value == target){
    return n;}
  if(target < n->value){
    return search(n->left, target);}
  if(target  > n->value){
    return search(n->right, target);}
  else return nullptr;
}

// Lab 4
// find the minimum of the tree
Node* BST::minimum(){
  // call the recursive function passing the root
  if(root == nullptr){return root;}
  return minimum(root);  
}
// recursive friend of minimum
Node* BST::minimum(Node* n){
  // if the node is null, then return it
  if(n->left != nullptr){
    // keep going left
    return minimum(n->left);
  }
return n;
}

// Lab 4
// find the maximum of the tree
Node* BST::maximum(){
  // call the recursive function passing the root
  if(root == nullptr){return root;}
  return maximum(root);  
}

Node* BST::maximum(Node* n){
  // if the right child is not null, recurse
  if(n->right != nullptr){return maximum(n->right);}
  // else return this node
  return n;
}

// Lab 3
// insert the inboud value into the BST
void BST::insertValue(int val){
  root = insertValue(root, val );
}
//  recursive partner of the above function
Node* BST::insertValue(Node* n, int val){
  if(n==nullptr){
    Node* m = new Node;
    m->value = val;
    return m;
  }
  else if(val < n->value){n->left = insertValue(n->left, val);}
  else if(val > n->value){n->right = insertValue(n->right, val);}
  size++;
  return n;
}

// delete the value passed from the BST
void BST::deleteValue(int val){
  // search for the value in the tree and assign to the returned node
  // Node* n = search(val);
  
  // if the node is empty, exit 
  if(root== nullptr){return;}
  // call the recursive version
  root = deleteValue(root, val);
}

Node* BST::deleteValue(Node* n, int val){
  // find the node to delete from the tree
  if(n != nullptr){
    // if the value is less go right
    if(n->value < val){
      n->right = deleteValue(n->right, val);
    }
    // if the value is more go left
    else if(n->value > val){
      n->left = deleteValue(n->left, val);
    }
    // no childs
    else if(n->left == nullptr && n->right == nullptr){
      n = nullptr;
      size--;
      return n;
    }    
    // 1 childs - left
    else if(n->right == nullptr && n->left != nullptr){
      n = n->left;
      size--;
      return n;
    }
    // 1 childs - right
    else if(n->left == nullptr && n->right != nullptr){
      n = n->right;
      size--;
      return n;
    }
    // if node to delete has 2 childs 
    else if(n->right != nullptr && n->left != nullptr){
      Node* m = minimum(n->right);
      n->value = m->value;
      n->right = deleteValue(n->right, m->value);
      size--;
      return n;
    }
  } 
  return n;
}

// Lab 3
// check if the node is a BST
bool BST::isBST(Node* n){
  int low = INT_MIN;
  int high = INT_MAX;

  return isBST(n, low, high);
}
// recursive partner to the above
bool BST::isBST(Node* n, int low, int high){
  if( n == nullptr ){return true;}
  if(n->value < low || n->value > high){return false;}
  return isBST(n->left, low,  n->value) && isBST(n->right, n->value, high);
}

void BST::preOrder(Node* n, vector<Node*> &order){
  if(n == nullptr){return;}
  order.push_back(n);
  preOrder(n->left, order);
  preOrder(n->right, order);
}

void BST::inOrder(Node* n, vector<Node*> &order){
  if(n == nullptr){return;}
  inOrder(n->left, order);
  order.push_back(n);
  inOrder(n->right, order);
}

void BST::postOrder(Node* n, vector<Node*> &order){
  if(n == nullptr){return;}
  postOrder(n->left, order);
  postOrder(n->right, order);
  order.push_back(n);
}