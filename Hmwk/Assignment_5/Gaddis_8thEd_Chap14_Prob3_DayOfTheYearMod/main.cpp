/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #
 * 
 * Problem: 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
# include "YrDay.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int date;
    string mon;
    
    //Input Values
    cout<<"Enter Month: ";
    cin>>mon;
    cout<<"Enter Day: ";
    cin>>date;
    
    //Process by mapping inputs to outputs
    YrMonth dayNow(mon, date);
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}