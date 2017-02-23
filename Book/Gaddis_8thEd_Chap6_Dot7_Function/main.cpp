/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 3:27 PM
 * Purpose: Homework 6.7
 * 
 * Problem: Write a function prototype for the timesTen function you wrote in 
 *      Question 6.6.
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
int xTen(int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int num, prod;
    
    //Input Values
    cout<<"Input Number: ";
    cin>>num;
    
    //Process by mapping inputs to outputs  
    prod = xTen(num);
    
    //Output values 
    cout<<"\nThe product of your number times ten is "<<prod<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

int xTen(int num) {
    int result;
    result = num*10;
    return result;
}