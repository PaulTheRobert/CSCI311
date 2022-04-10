#ifndef AIRPLANE_H
#define AIRPLANE_H

// Airplane.h
// Project 2
// created by: paul davis
// created on: 03/30/2022



using namespace std;

// Airplane class to hold the data for each airplane object
class Airplane{
    public:
        // constructor
        Airplane(){
            // initialize member variables
            id          = -1;
            enterTime   = -1;
            emergency   = -1;
            priority    = -1;            
        };

        // destructor
        ~Airplane(){}
    private:
        // declare private member variables
        int     id;
        int     enterTime;
        bool    emergency;
        int     priority; 
};
#endif