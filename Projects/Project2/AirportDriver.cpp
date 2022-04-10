// Project 2
// created by: paul davis
// created on: 03/22/2022
/*
    TODO
    1) Impliment an Airplane Class


    *) Write an Output function?
*/

#include <iostream>
#include "Airplane.h"
using namespace std;

int main(){
    cout<<"Still wortking on it"<<endl;
    return 0;    
    // declare an empty vector to hold the incoming airplane objects

    // declare three empty priority Queues 
        // Emergency
        // AwaitingTakeoff
        // AwaitingLanding
    
    // for each line in the input file, read it into an Airplane object, and store that object in a vector  
    

    // impliment a loop to count the time steps
    // what will indicate time to exit? When both queues are empty

    // 1. Add any new aircraft to the simulation
        // while timestep == airplane input time 
        // pop the airplane off the vector
        // add it to its appropriate priority queue
            // Emergency
            // AwaitingTakeoff
            // AwaitingLanding

        // write out "Entering Simulation"


    // 2. Perform actions for runways A and B
        // THINK ABOUT THIS 

    // 3. Update priorities
        // THIS is where you check for the distance from time enter to current time stamp for each plane
    
    // 4. Increment time
    // It is possible for an aircraft to enter the simulation and leave (takeoff or land) in the same time step.
}
