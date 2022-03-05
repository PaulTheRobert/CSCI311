// CSCI 311 - Spring 2022
// Lab 2 Skeleton
// Author: paul davis

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
// calculates the triangle number for n
int triangleNum(int n){
  // base case n = 0
  if(n==0){return 0;}
  // recursive case add n to the rest of the list
  return(n + triangleNum(n - 1));
}

//generates fib seq through n and returns sum
int rFib(int n){
  // base cases
  if(n == 0){return 0;}
  if(n == 1){return 1;}
  return rFib(n-1) + rFib(n-2);
}

// this is not required to be used
// its possible to write this without a helper function, esp if the vector is not a constant.
// use the integer i in the helper functio to keep track of where we are in the index
// this is how we accomplish "the rest of v"
int rSumHelper(const vector<int> &v, int i){
  // we want to stop when i gets past the size of the vector
  if (i >= v.size()){return 0;}
  return v[i] + rSumHelper(v, i+1);
  
}

// we want the sending funtions (user) to only pass the vector
// but a helper function allows us to store extra data that lets us solve recursively
int rSum(const vector<int> &v){
  // both base cases here are not striclty necessary.
  // writing multiple base cases can help us to visualize whats going on
  // base case 0
  if(v.size() == 0){return 0 ;}
  // base case 1 
  if(v.size() == 1){return v[0];}
  //recursive call
  // pull the first element out of the vecotr and add it to the sum of the rest of the vector
  // passing the 1 works because the next time around the vector is smaller relatively speaking
  return v[0] + rSumHelper(v, 1);
}

// this helps by tracking the index of the vector
int rMaxHelper(const vector<int> &v, int start){  
  // stop when start equals size of the vector
  if(start == v.size()){return v[start];}  
  return max(v[start], rMaxHelper(v, start + 1));  
}

// this will be like sum - us rSum as a guide
int rMax(const vector<int> &v){
  // base cases
  // if the vector is empty the max is 0
  if(v.size() == 0){return INT_MIN;}
  // if the vector has one element the the max is the value of that one element
  if(v.size() == 1){return v[0];}
  //recursive call will use the helper function to track the index and hide it from the user just like the Rsum
  // compare first position to result of helper call
  return max(v[0], rMaxHelper(v, 1));
  // max(1, max(2, max(3, 4)))
}

//check if the vector is sorted btw start and end, inclusive. 
bool isSorted(const vector<int> &v, int start, int end){
  // are the values in the vector sorted?
  // base case
  // empty vector
  if(v.size() == 0){return true;}
  // vector of 1
  if(v.size() == 1){return true;}
  //recursive case
  // the start shouldnt exceed the end. Its inclusive so we need to include the end
  // you cant compare to the value returned by isSorted perSe - its a bool
  if(start < end){
    // cout<<"v[start]: "<<v[start]<<" "
    // compare two sequential values
    // if sorted acending, call recurse - else return false
    // NOTE make sure you allow for EQUALITY!!!
    if(v[start] <= v[start +1]){return isSorted(v, start +1, end);}
    else{return false;} // this is a comparison it returns a bool;
  }
  else{return true;}
}
// Depricated 
// bool isPalindromeHelper(string s, int start, int end){

//   return false;
// }

// check if string is palendrome
// first and last charachter should match - if so truncate first and last charachters and recurs
bool isPalindrome(string s){
  
  // base case the sting is 1 char or less
  if(s.length() <= 1){return true;}
  //if first == last, erase first and last, call recurse
  // cout<<"s[0]: "<<s[0]<<"s[s.(length)]: "<<s[s.length()-1]<<endl;
  if(s[0] != s[s.length()-1]){return false;}
  // chop the ends off s before sending through again
  s.erase(0);
  s.erase(s.length());  //no -1 because length just got shorter with erase(0)
  return isPalindrome(s);
  
}

// find the target value in the sorted vector
// initially low is passed a 0 and high is passed v.size()-1 from main
// think of low and high as indexes not values! 
// Carter's note: 
// For a binary search, we want to check the element in the middle of low and high 
// and divide the search space in half at each step.
int rBinarySearch(const vector<int> &v, int low, int high, int target){
  int mid = v.size()-1;
  // base case - the list is empty
  if(v.size() == 0) return -1;
  // base case - 1 item in the list
  if(v.size() == 1){return v.size() == target;}
  //split the list
  if(v[mid] == target){return true;}
  if(v[mid] < target){return rBinarySearch(v, low, v.size()/2, target);}
  if(v[mid] > target){return rBinarySearch(v, v.size()/2, high, target);}
  return false;
  }


  // base case - the indexes meet without having found the target
  // if(low > high){return -1;}
  // // base case either of the values at the top or bottom match return true
  // // i think im failing to leverage the sorting in the vector. . . 
  // if(target == v[low])  { return low;}
  // if(target == v[high]) { return high;}
  // recurse with next index closing in from the sides toward the center
  // return rBinarySearch(v,low + 1, high - 1, target);
// }

bool rSubsetSum(const vector<int> &v, int start, int target){
  // what is the base case ? if the vector is empty
  // what about start? when start == v.size?
  // what about if any value in the vector is equal to the target
  if(v.size() == 0){
    if(target == 0){return true;}
    else{return false;}
  }
  
  // if you have reached the target, you are done, return true! target is moving, moving target lol
  if(target == 0){return true;}
  // if you get to the end, and no match, then false
  if(start == v.size()){return false;}

  // value can be excluded or included in the some . . . but what does that mean?
  // include - the index changes
  // how to combine these two? with an OR - because either just needs to e true.
  // exclude - target remains unchanged
  return(rSubsetSum(v, start+1, target -v[start])) || rSubsetSum(v, start+1, target);    
}

/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, start = 0, end = 0;
  vector<int> v;
  string s = "";
  switch (question){
    case 1: //triangleNum
      cout << "Triangle Number n: ";
      cin >> n;
      cout << triangleNum(n) << endl;
      break;
    case 2: //rFib
      cout << "Nth Fibonacci Number: ";
      cin >> n;
      cout << rFib(n) << endl;
      break;
    case 3: //rSum
      cout << "Recursive Sum Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSum(v) << endl;
      break;
    case 4: //rMax
      cout << "Recursive Max Vector Size: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rMax(v) << endl;
      break;
    case 5: //isSorted
      cout << "isSorted Vector Size: ";
      cin >> n;
      cout << "Start and End: ";
      cin >> start >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << isSorted(v, start, end) << endl;
      break;
    case 6: //isPalindrome
      cout << "String: ";
      cin >> s;
      cout << isPalindrome(s) << endl;
      break;
    case 7: //rBinarySearch
      cout << "Binary Search Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rBinarySearch(v, 0, v.size()-1, end) << endl;
      break;
    case 8: //rSubsetSum
      cout << "Subset Sum Vector Size: ";
      cin >> n;
      cout << "Target: ";
      cin >> end;
      cout << "Values: ";
      readIntVector(v, n);
      cout << rSubsetSum(v, 0, end) << endl;
      break;
  }

  return 0;
}

/**************************************************
 * Read a vector of integers in from cin          *
 * v - vector<int> & - the integer vector to fill *
 * n - int - the number of integers to read       *
 * ************************************************/
void readIntVector(vector<int> &v, int n){
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> m;
    v.push_back(m);
  }
}
