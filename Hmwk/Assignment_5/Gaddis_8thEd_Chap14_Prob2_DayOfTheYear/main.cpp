/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #2 Day of the Year
 * 
 * Problem: Assuming that a year has 365 days, write a class named DayOfYear 
 *  that takes an integer representing a day of the year and translates it to a 
 *  string consisting of the month followed by day of the month. For example,
 *          Day 2 would be January 2 .
 *          Day 32 would be February 1 .
 *          Day 365 would be December 31.
 *  The constructor for the class should take as parameter an integer 
 *  representing the day of the year, and the class should have a member 
 *  function print() that prints the day in the month–day format. The class 
 *  should have an integer member variable to represent the day and should have 
 *  static member variables holding string objects that can be used to assist in 
 *  the translation from the integer format to the month-day format. 
 *      Test your class by inputting various integers representing days and 
 *  printing out their representation in the month–day format.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "DayYr.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int userIn;
    
    //Input Values
    do {
        cout<<"Enter Day: ";
        cin>>userIn;
        if (userIn<=0||userIn>365) cout<<"\nInvalid Input!\n\n";
    } while(userIn<=0||userIn>365);
    
    //Process by mapping inputs to outputs
    DayOfYr monDate(userIn);
    
    //Output values
    monDate.prntDay();
   
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}