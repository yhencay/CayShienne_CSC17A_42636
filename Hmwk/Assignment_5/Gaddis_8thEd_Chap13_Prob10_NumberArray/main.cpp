/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #10 Number Array
 * 
 * Problem: Design a class that has an array of floating-point numbers. The 
 *      constructor should accept an integer argument and dynamically allocate 
 *      the array to hold that many numbers. The destructor should free the 
 *      memory held by the array. In addition, there should be member functions 
 *      to perform the following operations:
 *              • Store a number in any element of the array
 *              • Retrieve a number from any element of the array
 *              • Return the highest value stored in the array
 *              • Return the lowest value stored in the array
 *              • Return the average of all the numbers stored in the array
 *      Demonstrate the class in a program.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int sizeAry, access;
    bool z=true;
    
    //Input Values
    cout<<"How many elements do you want to input? ";
    cin>>sizeAry;
    
    //Process by mapping inputs to outputs
    NumAry numbers(sizeAry);
    
    //Output values
    do {
        cout<<"\nInput number of element in the array you want to access.\n\n";
        cout<<"Input Number: ";
        cin>>access;
        if (access<1||access>sizeAry) cout<<"\nElement does not exist!\n\n";
        else {
            access-=1;
            cout<<"\nThe element is: "<<numbers.getNum(access);
            z=false;
        }
    } while(z);
    
    cout<<"\nHighest Value: "<<numbers.highest()<<endl;
    cout<<"Lowest Value: "<<numbers.lowest()<<endl;
    cout<<"Average: "<<numbers.average()<<endl;
     
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}