// CSCI 311 - Spring 2022
// Exam 1
// Author: Paul Robert Davis

#include <iostream>
#include <vector>
using namespace std;
// dev notes
// to compile: g++ -std=c++11 exam_1.cpp
// to execute: ./a.out

// compare two strings of equal length. If different, return a value for how many charachters are different, if different lengths return -1
int hammingDist(string a, string b){
    int ham = 0;
    //check that strings are the same length
    if(a.length()!=b.length()){return -1;}
    else{
        for(int i = 0; i < a.length(); i++){
            a[i] == b[i] ? 0 : ham++;
        }
        return ham;
    }
}

string reverse(string a){
    // base case
    if(a.size() <= 1){return a;}
    // cout<<"a: "<<a<<endl;
    
    a = reverse(a.substr(a.size()-1,a.size()-2));

    // string temp;
    // for(int i = a.size()-1 ; i > 0; i--){
    //     temp.push_back(a[i]);
    // } 
    // cout<<"temp: "<<temp<<endl;
    // a = reverse(temp);

    //is the string at least 2 long?
    // if(a.length() < 2){return a;}

    // // then swap two end characters
    // cout<<endl<<"before: "<<a<<endl;
    
    // char temp = a[0];
    // a[0] = a.back();
    // a[a.length()-1] = temp;
    // cout<<endl<<"after: "<<a<<endl;
    
    // reverse(a.substr(1, a.length()-2));
    // // call reverse recurse shorten string from both ends
    // cout<<a<<endl;
    // //how to knit them back together again?
    return a;
}

string runLengthEncoding(string a){
    // make a vector to track each unique char
    // make a vector to count how many times each char occurs
    // use a common index for both arrays
    vector<char> c;
    vector<int> n;

    // loop through every character in the inbound string
    for(char a : a){
        // check if the character is in the character array
        bool exists = false;
        int i = 0;
        // for(int i = 0; i < c.size(); i++){
        while(!exists && i < c.size()){
            // on match, incriment the value in the common index of n
            // set exists to true to break the while loop
            if(c[i] == a){
                n[i] = n[i] + 1;
                exists = true;
            }
            i++;
        }
        // if this charachter was not in the charachter array, add it to the end, and add a 1 to the end of n at the common index
        if(!exists){
            c.push_back(a);
            n.push_back(1);
        }
    }

    // now both arrays contain the run length encoding. combine them into a string
    string newString;
    for(int i = 0; i < c.size(); i++){
        newString += to_string(n[i]);
        newString.push_back(c[i]);
    } 
    return newString;
}

// helper function for merge sort
// recieve two vecotrs of possible unequal size
// return 1 sorted vector
vector<int> merge(vector<int> A, vector<int> B){
    vector<int> C;
    
    // cout<<endl<<"A: ";
    // for(int a : A){cout<<a<<",";}
    // cout<<endl<<"B: ";
    // for(int b : B){cout<<b<<",";}

    int a=0;
    int b=0;        
    // for(a; a < A.size() && b < A.size(); a += 0){
    while(a < A.size() && b < B.size()){
            if(A[a] < B[b]){
                C.push_back(A[a]);
                a++;
            }else{
                C.push_back(B[b]);
                b++;
            }
    }
    // if there is anything left in A its all greater than the last val in B so bring it all it!
    if(a < A.size()){
        for(int i = a; i < A.size(); i++){
            C.push_back(A[i]);
        }
    }  
    // if there is anything left in B its all greater than the last val in A so bring it all it!
    if(b < B.size()){
        for(int i = b; i < B.size(); i++){
            C.push_back(B[i]);
        }
    }
    // cout<<endl<<"C: ";
    // for(int c : C){cout<<c<<",";}   
    // cout<<endl;

    return C;
}

// sorts using merge sort recursive implimentation
vector<int> mergeSort(vector<int> &v){
    // base case v.size() is 1
    if(v.size() == 1){return v;}
    
    int p = v.size()/2;     // middle of list
    int r = v.size();       // end of list

    vector<int> A;
    vector<int> B;
    // split the list in two
    for(int i = 0; i < p; i++){
        A.push_back(v[i]);
    }

    for(int i = p; i<r; i++){
        B.push_back(v[i]);
    }

    vector<int> C;
    // call merge sort recurese with merge to do the putting back together again
    C = merge(mergeSort(A), mergeSort(B));
    
    return C;
    }
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