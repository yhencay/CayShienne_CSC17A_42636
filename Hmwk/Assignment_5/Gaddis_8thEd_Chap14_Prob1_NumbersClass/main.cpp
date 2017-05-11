/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #7 Numbers Class
 * 
 * Problem: Design a class Numbers that can be used to translate whole dollar 
 *      amounts in the range 0 through 9999 into an English description of the 
 *      number. For example, the number 713 would be translated into the string 
 *      seven hundred thirteen , and 8203 would be translated into eight 
 *      thousand two hundred three . The class should have a single integer
 *      member variable:
 *              int number;
 *      and a static array of string objects that specify how to translate key 
 *      dollar amounts into the desired format. For example, you might use 
 *      static strings such as
 *          string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
 *          string hundred = "hundred";
 *          string thousand = "thousand";
 *  The class should have a constructor that accepts a nonnegative integer and 
 *  uses it to initialize the Numbers object. It should have a member function 
 *  print() that prints the English description of the Numbers object. 
 *  Demonstrate the class by writing a main program that asks the user to enter 
 *  a number in the proper range and then prints out its English description.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "NumCls.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int input;
    
    //Input Values
    do {
        cout<<"Enter number from 0-9999."<<endl<<endl;
        cout<<"INPUT: ";
        cin>>input;
        if (input<0||input>9999) cout<<"\nInput Invalid!\n\n";
    } while(input<0||input>9999);
    
    
    //Process by mapping inputs to outputs
    Numbers trans(input);
    
    //Output values
    cout<<endl;
    trans.prntWrd();
    cout<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}