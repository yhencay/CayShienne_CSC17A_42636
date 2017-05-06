/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #1 Date
 * 
 * Problem: Design a class called Date. The class should store a date in three 
 *      integers: month, day , and year. There should be member functions to 
 *      print the date in the following forms:
 *               12/25/2014
 *               December 25, 2014
 *               25 December 2014
 *    Demonstrate the class by writing a complete program implementing it.
 *  Input Validation: Do not accept values for the day greater than 31 or less 
 *     than 1. Do not accept values for the month greater than 12 or less than 1.
 */

//System Libraries
#include <iostream>
#include <string>

using namespace std;

//User Libraries
#include "Date.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int m, d, y;
    
    //Input Values
    cout<<"Input Month: ";
    cin>>m;
    while(cin.fail()||(m<1)||(m>12)) {
        cout<<"\nInvalid Input. Try again!"<<endl<<endl;
        cout<<"Input Month: ";
        cin.clear();
        cin>>m;
    }
    
    cout<<"Input Day: ";
    cin>>d;
    while(cin.fail()||(d<1)||(d>31)) {
        cout<<"\nInvalid Input. Try again!"<<endl<<endl;
        cout<<"Input Day: ";
        cin.clear();
        cin>>d;
    }
    
    cout<<"Input Year: ";
    cin>>y;
    
    //Process by mapping inputs to outputs
    Date prnDate(m, d, y);
    
    //Output values
    prnDate.prntD8();
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}