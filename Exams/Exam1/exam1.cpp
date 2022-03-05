// CSCI 311 - Spring 2022
// Exam 1
// Author: ** YOUR NAME HERE ***

#include <iostream>
#include <vector>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/

/*********************************************************************************************************
 * TESTING                                                                                               *
 * When testing your functions, the main below expects input in a certain format for each question.      *
 * The first line of input should always the question number (1-4). More details are provided regarding  *
 * the input for each question in the main itself.                                                       *
 * To test, you may run program and provide input by hand or you may provide a file as input directly    *
 * from the terminal. For example, suppose you compile your program to a.out and that you have a file    *
 * named "test_01.in" containing input in the appropriate format for question 1. Then running            *
 * ./a.out < test_01.in                                                                                  *
 * will run your program using the lines of test_01.in as input. This can be a good way to save time and *
 * to save different test cases when testing your code.                                                  *
 * *******************************************************************************************************/
void readIntVector(vector<int> &v, int n);
int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  string a = "";
  string b = "";
  int n = -1;
  vector<int> v;
  vector<int> s;
  switch(question){
    case 1: // Hamming distance
      /*************************************
       * Input format:                     *
       * 1                                 *
       * string 1, no whitespace, nonempty *
       * string 2, no whitespace, nonempty *
       * ***********************************/
      cout << "Hamming distance - Enter two strings: ";
      cin >> a >> b;
      cout << hammingDist(a, b) << endl;
      break;
    case 2: // reverse
      /**********************************************
       * Input format:                              *
       * 2                                          *
       * string to reverse, no whitespace, nonempty *
       * ********************************************/
      cout << "Reverse - Enter one string: ";
      cin >> a;
      cout << reverse(a) << endl;
      break;
    case 3: // run-length encoding
      /*********************************************
       * Input format:                             *
       * 3                                         *
       * string to encode, no whitespace, nonempty *
       * *******************************************/
      cout << "Run-length encoding - Enter one string: ";
      cin >> a;
      cout << runLengthEncoding(a) << endl;
      break;
    case 4: // merge sort
      /*************************************
       * Input format:                     *
       * 4                                 *
       * length of vector                  *
       * integers to include in the vector *
       * ***********************************/
      cout << "Merge sort - Enter the size of the vector to sort: ";
      cin >> n;
      cout << "Enter the elements of the vector: ";
      readIntVector(v, n);
      s = mergeSort(v);
      for (int i = 0; i < s.size(); i++){ cout << s[i] << " "; }
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