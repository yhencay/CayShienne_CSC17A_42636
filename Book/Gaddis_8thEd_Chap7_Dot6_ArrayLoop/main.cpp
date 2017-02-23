/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 3:27 PM
 * Purpose: Homework 7.6
 * 
 * Problem: What is the output of the following code?
 * 
 *      int values[5], count;
 *      for (count = 0; count < 5; count++)
 *          values[count] = count + 1;
 *      for (count = 0; count < 5; count++)
 *          cout << values[count] << endl;
 * 
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
    int values[5] = {}, count;
    
    //Input Values
    //Process by mapping inputs to outputs  
    for (count=0;count<5;count++) values[count] = count+1;
    
    //Output values 
    for (count=0;count<5;count++) cout<<values[count]<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}