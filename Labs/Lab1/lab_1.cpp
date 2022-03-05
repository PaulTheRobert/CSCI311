// CSCI 311 - Spring 2022
// Lab 1 Skeleton
// Author: Carter Tillquist

#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>
using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
// calculate the collatz length for any given integer
// if even divide by 2, if odd, multiply by 3 and add 1
// ends when 1
int collatzLength(int n){
  // counter var
  int count = 0;
  // needs to exit when n = 1
  while (n != 1){
    // check for even
    if(n%2 == 0){
      // if even divide by 2
      n=n/2;
    }
    // if not even, then its odd
      else{
      // multiply by 3 and add 1
      n = 3*n+1;
    }
    // incriment the count
    count ++;
  }
  return count; 
}

// Write a function void printStats(const vector<int> &v) that prints the minimum, max and mean seperated by space
void printStats(const vector<int> &v){
  //declare variables to be used in output
  int min, max;
  double mean = 0;
  if(v.empty()){
    cout<<"Empty vector"<<endl;
  }
  else{
      min  = v[0];
      max  = v[0];      

      for(int i = 0; i < v.size(); i++){
        // check if the current value is less than min, if so assign to min
        v[i] < min ? min = v[i] : 0;
        //check if the current value is greater than, if so assign to max
        v[i] > max ? max = v[i] : 0; 
        // accumulate the values in the mean
        mean += v[i];
        }
      // once the loop exits calculate the mean
      mean = mean/(v.size());      
      //construct the output string
      cout<<min<<" "<<mean<<" "<<max<<endl;    
    }
  }
// returns the sum of all multiples of values in the vector nums less than n
// note that common multipls are only counted once
int sumMultiples(const vector<int> &v, int n){
  //initialize accumulator 
  int sum = 0;
  // iterate over all pos ints < n
  for(int i = 0; i < n; i++){
    // for each val in the vector, check if i is a multiple, if yes add to accumulator and skip to next int.
    for(int x : v){
      // cout<<"i: "<<i<<"% x: "<<" = "<<i<<endl;
      if(i%x==0){
        sum += i;
        break;
      }
    }
  }
  return sum;
}

void greaterThanK(vector<int> &v, int k){
  // set an incriment counter
  int count = 0;
  //loop through the vector
  for(int i : v){
    // if the value in the vector is less than k, remove it from the vect
    if(i <= k){
      v.erase(v.begin() + count);
    }    
  }
}

void pivot(vector<int> &v, int k){
}

bool isSubarray(const vector<string> &a, const vector<string> &b){
  bool isSub = false;
  // loop through vector a
  for(string ia : a){
    //loop vector b
    for(string ib : b){    
      if(ia == ib){
        //if the value in == b set is sub to true and break. 
        isSub = true;
        break;
      }else{
        isSub = false;
      }
    };
  }
  return isSub;
}

bool isPrimeA(int n){
  bool isPrime =                                                                            false;
  //n mod i = 0 for any 2 <= i < n.
  for(int i= 2; i < n; i++){
    //if n < 2 return false
    // if ne == 2 return true 

    i%n==0 ? isPrime =true : isPrime = false;

  }
  return false;
}

int sumPrimesA(int n){
  int sum = 0;
  
  for(int i = 1; i < n; i++){
    if(isPrimeA(i)){
    sum =+  i;
    }
  }

  return sum;
}

bool isPrimeB(int n){

  //check if less than square root because thats how factors work
  //ex: 
  //  return false;
}

int sumPrimesB(int n){
  return 0;
}

int sieveOfErathosthenes(int n){
  // see wikipedia for vizualization
  // finish lab 1!!!
  return 0;
}

/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);
void timePrimes();

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, k = 0, m = 0;
  vector<int> v;
  string s = "";
  vector<string> a;
  vector<string> b;

  switch (question){
    case 1: //collatzLength
      cout << "Collatz Sequence n: ";
      cin >> n;
      cout << collatzLength(n) << endl;
      break;
    case 2: //printStats
      cout << "Print Stats Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Stats: " << endl;
      printStats(v);
      break;
    case 3: //sumMultiples
      cout << "Sum Multiples Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Max Value: ";
      cin >> k;
      cout << "Sum: ";
      cout << sumMultiples(v, k) << endl;
      break;
    case 4: //greaterThanK
      cout << "Greater than K Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "k: ";
      cin >> k;
      cout << "Result: ";
      greaterThanK(v, k);
      for (int j = 0; j < v.size(); j++){ cout << v[j] << " "; }
      break;
    case 5: //pivot
      cout << "Pivot Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Pivot: ";
      cin >> k;
      cout << "Result: ";
      pivot(v, k);
      for (int j = 0; j < v.size(); j++){ cout << v[j] << " "; }
      break;
    case 6: //isSubarray
      cout << "Is Subarray Array Sizes: ";
      cin >> n >> m;
      cout << "Values for First Vector: ";
      for (int i = 0; i < n; i++){
        cin >> s;
        a.push_back(s);
      }
      cout << "Values for Second Vector: ";
      for (int i = 0; i < m; i++){
        cin >> s;
        b.push_back(s);
      }
      cout << "Result: ";
      cout << isSubarray(a, b) << endl;
      break;
    case 7: //primes
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sums: " << sumPrimesA(n) << " " << sumPrimesB(n) << " " << sieveOfErathosthenes(n) << endl;
      break;
    case 8: //time primes
      cout << "Time Primes" << endl;
      timePrimes();
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

/***************************************************************************************************
 * Testing run times of different approaches to finding the sum of prime numbers under a threshold *
 * *************************************************************************************************/
void timePrimes(){
  int sum = -1;
  chrono::high_resolution_clock::time_point start;
  chrono::high_resolution_clock::time_point end;
  double elapsed = -1;
  vector<int> x = {10, 100, 1000, 10000, 100000, 500000};
  for (int i = 0; i < x.size(); i++)
  {
    cout << "Value: " << x[i] << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesA(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "A ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesB(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "B ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sieveOfErathosthenes(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "C ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;
    cout << endl << endl;
  }

  cout << "Sieve of Eratosthenes on primes below 1 million" << endl;
  start = chrono::high_resolution_clock::now();
  long sum2 = sieveOfErathosthenes(1000000);
  end = chrono::high_resolution_clock::now();
  elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
  cout << "Sum: " << sum2 << ", Time elapsed: " << elapsed << endl;
  cout << endl << endl;
}
