// CSCI 311 - Spring 2022
// Lab 6 - Hash Table cpp
// Author: Carter Tillquist
// implimented by: paul davis

#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include "HashTable.h"

// constructor
HashTable::HashTable(){
  //initialize all the private member variables  
  size = 11;          // default size 11
  numElements = 0;    /// starts with 0 elements
  p = 31;             // constant for the rolling hash
  
  table.resize(size);      // initilize table with empty vectors
  for(int i=0; i<size; i++){
    table[i].resize(0);   // initialize each subvector
  }

}
// parameterized constructor
// mult = p
HashTable::HashTable(int s, int mult){
  // initilize the priv member variables
  size = s;
  numElements = 0;
  p = mult;
  
  table.resize(size);      // initilize table with empty vectors
  for(int i=0; i<size; i++){
    table[i].resize(0);   // initialize each subvector
  }
}

int HashTable::getSize(){ return size; }
int HashTable::getNumElements(){ return numElements; }
int HashTable::getP(){ return p; }

void HashTable::printTable(){
  cout << "HASH TABLE CONTENTS" << endl;
  for (int i = 0; i < table.size(); i++){
    if (table[i].size() > 0){
      cout << i << ": ";
      for (int j = 0; j < table[i].size()-1; j++){
        cout << table[i][j] << ", ";
      }
      cout << table[i][table[i].size()-1] << endl;
    }
  }
}

int HashTable::search(string s){
  // assign the hashvalue for convinience
  int loc = hash(s);

  // loop through each string at that location and compare for a match
  for(int i =0; i < table[loc].size(); i++){
    if(table[loc][i] == s){return loc;}
  }
  return -1;
}

void HashTable::insert(string s){
  //hash the string
  int loc = hash(s);
  // insert the string at the end of the subvector
  table[loc].push_back(s);

}

void HashTable::remove(string s){
}

void HashTable::resize(int s){
}

int HashTable::hash(string s){  
  int h = 0; // try using an int, and an unsigned int here -- are the results different for some longer words? why? overflow point differes from signed to unsigned?
  
  // for each letter in the string convert it to ASCII
  for(int i = 0; i < s.size(); i++){
    // raise p to the power of the char index
    unsigned int pp = pow(p, i);

    // convert the current char to ASCII
    int c = s[i];

    // accumulate the product of pp and c
    h += pp*c;    
  }
  // return the result mod m
  return h%size;
}