/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 3:27 PM
 * Purpose: Homework 5.11
 * 
 * Problem: Write a for loop that displays every fifth number, zero through 100.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    //Input Values
    //Process by mapping inputs to outputs   
    //Output values    
    for (int count=1; count<=100; count++) {
        if (count%5==0) cout<<count<<endl;
    }
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}