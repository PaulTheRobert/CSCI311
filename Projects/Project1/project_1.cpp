// paul davis
// csci 311
// project 1
// 02/08/2022 

// dev notes
// to compile: g++ -std=c++11 project_1.cpp
// to execute: ./a.out

/*
    PROCESS FLOW
        No Runtime Inputs - Default should output 2.1

        To Do

        Write a class to store the data for output. Store the objects in a vector
        and then write the file at the very end from vector of objects. This keeps the file write time to a min.
        We know this thing will take some time to run. 

        Class Output
            Member Variables:
                index
                algorithm
                case
                vector size
                duration

        2.1 Confirm that the algorithms function to sort the vectors 
            call testAlgorithms(10, 100)
                
                
          
        2.2 Test the algorithm asymptotic runtime 
          
    -- choose 5 lengths that will exhibit asymptotic runtime behavior 
    -- set a vector to each of the 5 sizes, loop through it, passing the sizes to testAlgorithims(50, v[i])      
    
    runExperimentsOnAlgorithms(x = how many vectors, i = vector size);   -- test how many algorithms to test
          2.1 Run Bubble Sort tests - call testAlgorithms()
            2.1.1 Create x Random Vectors
            2.1.2 Bubble Sort each vector in ASC,  logging duration data in Output CLASS object.  This is the AVERAGE case. All x vectors are ASC
            2.1.3 Bubble Sort each vector in DESC, logging the duration data in Output CLASS object. This is the WORST case. ALL x vectors are DESC.
            2.1.5 Bubble Sort each vector in DESC, logging duration data in the Output CLASS object. This is the BEST case. All x vectors are DESC.
            2.1.6 Delete x Vectors
          2.2 Run Insertion Sort tests
            2.2.1 Create x Random Vectors
            2.2.2 Insertion Sort each vector in ASC, logging duration data in Output CLASS object.  This is the AVERAGE case. All x vectors are ASC
            2.2.3 Insertion Sort each vector in DESC, loggingthe duration data in Output CLASS object. This is the WORST case. ALL x vectors are DESC.
            2.2.5 Insertion Sort each vector in DESC, logging duratio data in the Output CLASS object. This is the BEST case. All x vectors are DESC.
            2.2.6 Delete x Vectors      
          2.3 Run Selection Sort tests
            2.3.1 Create x Random Vectors
            2.3.2 Selection Sort each vector in ASC, logging duration data in Output CLASS object.  This is the AVERAGE case. All x vectors are ASC
            2.3.3 Selection Sort each vector in DESC, loggingthe duration data in Output CLASS object. This is the WORST case. ALL x vectors are DESC.
            2.3.5 Selection Sort each vector in DESC, logging duratio data in the Output CLASS object. This is the BEST case. All x vectors are DESC.
            2.3.6 Delete x Vectors  
          2.4 Run Quicksort Tests
            2.4.1 Create x Random Vectors
            2.4.2 Quicksort Tests each vector in ASC, logging duration data in Output CLASS object.  This is the BEST case. All x vectors are ASC
            2.4.3 Quicksort Tests each vector in DESC, loggingthe duration data in Output CLASS object. This is the WORST case. ALL x vectors are DESC.
            2.4.5 Quicksort Tests each vector in DESC, logging duration data in the Output CLASS object. This is the WORST case. All x vectors are DESC.
            2.4.6 Delete x Vectors               



*/

#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;

// -------------   SORT FUNCTIONS   --------------------
// check if a vector is sorted recursivly
// vector sort order by switch 0 = ASC or 1 = DSC <-- not implimented, testing a reverse sort is not needed for this project.
// bool isSorted(vector<int> v, int start, int end){
bool isSorted(vector<int> v, int start){
    // base case - if v is <= 1
    // if(v.size() <= 1) {return true;}     //i think this was a bad base case because the size of v isnt changing
    if(start+1 == v.size()){return true;}
    // cout<<"start: "<<start<<" end: "<<start+1<<endl;
    // if(start <= end){
        // cout<<"start: "<<start<<" end: "<<start+1<<endl;
        // cout<<"a: "<< v[start] <<" <= "<<" b: "<< v[start+1]<<" = "<<(v[start] <= v[start + 1]) <<endl; 
        if(v[start] <= v[start + 1]) {
            return isSorted(v, start+1);
        }
        else{return false;}               
    // }
    return true;
}
// bubble sort
// sorts a vector in order by switch 0 = ASC or 1 = DSC
vector<int> bubbleSort(vector<int> v, int dir){
    bool sorted = false;
    // loop while the list is not sorted
    while(!sorted){        
        sorted = true;
        // loop through all items in the vector 
        for(int i = 0; i < v.size()-1; i++){
            // if the current value is greater than the following value, execute a swap
            // directional switch
            switch(dir){ 
                case 0:                     // ASC      
                    if(v[i] > v[i+1]){
                        int temp = v[i];
                        v[i] = v[i+1];
                        v[i+1] = temp;
                        sorted = false;
                    }
                    break;
                case 1:                     // DSC
                    if(v[i] < v[i+1]){
                        int temp = v[i];
                        v[i] = v[i+1];
                        v[i+1] = temp;
                        sorted = false;
                    }
                    break;
            }
        }
    }
    return v;
}

// insertion sort
// sorts a vector in order by switch 0 = ASC or 1 = DSC
vector<int> insertionSort(vector<int> v, int dir){
    int i = 1;
    while(i < v.size()){
        int j = i;
        // compare two side by side elements
        // if the second element is greater than the first - execute a swap
        // the swap moves through the sorted part of the vector to find where the val belongs
        // directional switch
        switch(dir){
            case 0:                     //ASC
                while (j > 0 && v[j] < v[j-1]){
                    int temp = v[j-1];
                    v[j-1] = v[j];
                    v[j] = temp;
                    j--;
                }
                break;
            case 1:                     // DESC
                while (j > 0 && v[j-1] < v[j]){
                    int temp = v[j];
                    v[j] = v[j-1];
                    v[j-1] = temp;
                    j--;
                }
                break;
        }            
        i++;
    }
    return v;    
}

// selection sort
// sorts a vector in order by switch 0 = ASC or 1 = DSC
vector<int> selectionSort(vector<int> &v, int dir){
    // iterate over the vector
    for(int i = 0; i< v.size()-1; i++){
        // initialize the min to the value at the current index
        int uMin  = i;
        // iterate through the vector to find the index of the minimum value
        // directional switch
        switch(dir){
            case 0:                     // ASC
                for(int j = i+1; j < v.size(); j++){
                    if(v[j] < v[uMin]){uMin = j;}
                }
                break;
            case 1:                     // DESC
                for(int j = i+1; j < v.size(); j++){
                    if(v[j] > v[uMin]){uMin = j;}
                }
                break;
        }
        // execute a swap with the value at the current index and the min
        int temp = v[i];
        v[i] = v[uMin];
        v[uMin] = temp;
    }
    return v;
}

// quicksort
// doin' it n*log(n) with recursion
vector<int> quickSort(vector<int> v){
        // if the list is less that 2 items, its sorted already, do nothing
        if(v.size() <= 1){return v;}
        
        // assign the pivot
        int pivot = v[0];   

        vector<int> A;
        vector<int> B;
        /// populate A and B by splitting on the pivot
        for(int i = 1; i < v.size(); i++){
            if(v[i] <= pivot){
                A.push_back(v[i]);
            }else
                B.push_back(v[i]);            
        }
 
        // call recursion
        A = quickSort(A);
        // for(int a : A){A.push_back(a);}
        B =  quickSort(B);
        // push the pivot to the now sorted list A
        A.push_back(pivot);           
        
        //rebuild the list by concatenating the lists with the pivot in the middle
        for(int b : B){
            // cout<<"pushing back: "<<b<<endl;
            A.push_back(b);            
            }
        return A;                           
}

// -------------   TEST FUNCTIONS   --------------------

// generate a vector of random integers
vector<int> randomVector(int size, int low, int high){
    // initialize vector of size
    vector<int> v(size, 0);
    
    // loop and populate the vector
        for(int i = 0; i< size; i++){
        // populate vector with random values
        v[i] = rand() % (high - low +1) + low;
    }
    return v;
}

// create multiple vectors in a vector that will be used for testing. 
// parameters( how many vectors to make | size of the vectors)
// make vectors
vector<vector<int>> buildVectors(int count, int size, int low, int high){
    vector<int> v(size, 0);
    vector<vector<int>> vect(count, v);
    // make a new vector for every count
    for(int i = 0; i<count; i++){
        // call the make random vector function
        vect[i] = randomVector(size, low, high);
    }
    return vect;
}

//print vector
// iterate through a 1D vector and print all values in order of index
void printVector(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";        
    }
    cout<<endl;
}

// caclulate and output summarized runtime data
void runTimeAnalysis(vector<double> v, bool csv){
    double min = v[0];
    double max = v[0];
    double sum = 0;
    // loop one for min, max and mean
    for(double &v : v){
        // check and set min / max
        v < min ? min = v : 0 ;
        v > max ? max = v : 0 ;
        // accumulate the sum
        sum += v;
    }
    
    double mean = sum / v.size();
    double var = 0;
    // loop 2 for variance
    for(double &v : v){
        var += (v-mean) * (v-mean);
    }
    var /= v.size();
    // calculate the standrd deviation
    double sd = sqrt(var);
    // output
    cout<< fixed << showpoint;
    cout << setprecision(4);

    if(!csv){cout<<"Minimum: "<< min << " sec; Mean: " << mean << " sec; Standard Deviation: " << sd <<" sec; Maximum: " << max << " sec;"<<endl<<endl;}

}

// 2.1 test all sorts and return runtimes
void testSorts(vector<vector<int>> vv){
    // keep track sorting 
    bool sorted = true;
    // vector to store times
    vector<double> runTimes;
    // initialize start & end 
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    
    //bubble sort -- preserve the randomness of the incoming vector for re-use
    for(vector<int> &v : vv){
        // set start time to measure 
        start = chrono::high_resolution_clock::now();
        // vector for checking if its sorted
        vector<int> sortTest = bubbleSort(v, 0);
        // test the sort - if not sorted set the sorted flag to false
        !isSorted(sortTest, 0) ? sorted = false : 0;
        // set end time
        end = chrono::high_resolution_clock::now();
        // calc run time and add to array
        runTimes.push_back(chrono::duration_cast<chrono::duration<double>>(end - start).count());
    }
    cout<<"Bubble sort on vectors of length "<< vv[0].size()<< endl;
    cout<<"Sorting " << (sorted ? " succesfull, sweetness!" : " failed" )<<endl;
    runTimeAnalysis(runTimes, 0);

    //insertion sort -- preserve the randomness of the incoming vector for re-use
    for(vector<int> &v : vv){
        // set start time to measure 
        start = chrono::high_resolution_clock::now();
        // vector for checking if its sorted
        vector<int> sortTest = insertionSort(v, 0);
        // test the sort - if not sorted set the sorted flag to false
        isSorted(sortTest, 0) ? 0 : sorted = false;
        // set end time
        end = chrono::high_resolution_clock::now();
        // calc run time and add to array
        runTimes.push_back(chrono::duration_cast<chrono::duration<double>>(end - start).count());
    }
    cout<<"Insertion sort on vectors of length "<< vv[0].size()<< endl;
    cout<<"Sorting " << (sorted ? " succesfull, sweetness!" : " failed" )<<endl;
    runTimeAnalysis(runTimes, 0);

    //selection sort -- preserve the randomness of the incoming vector for re-use
    for(vector<int> &v : vv){
        // set start time to measure 
        start = chrono::high_resolution_clock::now();
        // vector for checking if its sorted
        vector<int> sortTest = selectionSort(v, 0);
        // test the sort - if not sorted set the sorted flag to false
        isSorted(sortTest, 0) ? 0 : sorted = false;
        // set end time
        end = chrono::high_resolution_clock::now();
        // calc run time and add to array
        runTimes.push_back(chrono::duration_cast<chrono::duration<double>>(end - start).count());
    }
    cout<<"Selection sort on vectors of length "<< vv[0].size()<< endl;
    cout<<"Sorting " << (sorted ? " succesfull, sweetness!" : " failed" )<<endl;
    runTimeAnalysis(runTimes, 0);

    //Quick sort -- preserve the randomness of the incoming vector for re-use
    for(vector<int> &v : vv){
        // set start time to measure 
        start = chrono::high_resolution_clock::now();
        // vector for checking if its sorted
        vector<int> sortTest = quickSort(v);
        // test the sort - if not sorted set the sorted flag to false
        isSorted(sortTest, 0) ? 0 : sorted = false;
        // set end time
        end = chrono::high_resolution_clock::now();
        // calc run time and add to array
        runTimes.push_back(chrono::duration_cast<chrono::duration<double>>(end - start).count());
    }
    cout<<"Quick sort on vectors of length "<< vv[0].size()<< endl;
    cout<<"Sorting " << (sorted ? " succesfull, sweetness!" : " failed" )<<endl;
    runTimeAnalysis(runTimes, 0);            
}

// collect data on sorting run times
void generateData(){
    //open the file stream
    ofstream output;
    output.open ("runTimeAnalysis.csv");

    // initialize start & end 
    chrono::high_resolution_clock::time_point start;
    chrono::high_resolution_clock::time_point end;
    
    // set a vector tp hold the sizes of test vectors
    vector<int> size = {100, 500, 750, 1000, 10000};

    // vector to hold the vectors of vectors
    vector<vector<vector<int>>> tests;

    for(int i = 0; i < size.size(); i++){
        // initialize random vectors for each given length
        tests.push_back(buildVectors(50, size[i], 0, 1000));

        // loop through all vectors
        for(vector<int> v : tests[i]){  
            // bubble sort average
            // set start time to measure 
            start = chrono::high_resolution_clock::now();      
            // save a copy of the sorted vector, preserve the random vector
            vector<int> sortedV = bubbleSort(v, 0);      
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            double runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", AVG, BUBBLESORT, "<<runTime<<endl;
               
            // bubble sort best
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", BEST, BUBBLESORT, "<<runTime<<endl; 
            bubbleSort(sortedV, 0);

            // bubble sort worst
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            bubbleSort(sortedV, 1);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", WORST, BUBBLESORT, "<<runTime<<endl;

            // insertion sort avg
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            insertionSort(v, 0);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", AVG, INSERTIONSORT, "<<runTime<<endl;

            // insertion sort best
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            insertionSort(sortedV, 0);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", BEST, INSERTIONSORT, "<<runTime<<endl;

            // insertion sort worst
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            insertionSort(sortedV, 1);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", WORST, INSERTIONSORT, "<<runTime<<endl;

            // selection sort avg
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            selectionSort(v, 0);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", AVG, SELECTIONNSORT, "<<runTime<<endl;

            // section sort best
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            selectionSort(sortedV, 0);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", BEST, SELECTIONSORT, "<<runTime<<endl;

            // selection sort worst
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            vector<int> revSortedV = selectionSort(sortedV, 1);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", WORST, SELECTIONNSORT, "<<runTime<<endl;

            // quicksort avg
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            // sorting the random vector
            quickSort(v);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", AVG, QUICKSORT, "<<runTime<<endl;

            // quicksort best
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            // quicksorting a list sorted ASC
            quickSort(sortedV);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", BEST, QUICKSORT, "<<runTime<<endl;

            // quicksort worst 
            // set start time to measure 
            start = chrono::high_resolution_clock::now(); 
            // quicksorting a list sorted DSC
            quickSort(revSortedV);
            // set end time
            end = chrono::high_resolution_clock::now();
            // calc run time
            runTime = chrono::duration_cast<chrono::duration<double>>(end - start).count();
            // output
            output<<"SIZE:"<<v.size()<<", WORST, QUICKSORT, "<<runTime<<endl;
        }
    }
    
    for(int i = 0; i < size.size(); i++){
        
    }

    // close the file
    output.close();
}

// main
int main(){
    // seed the random
    srand(time(NULL));
    
    vector<vector<int>> test2_1 = buildVectors(10, 100, 0, 1000);
    testSorts(test2_1);
    // generateData();

}