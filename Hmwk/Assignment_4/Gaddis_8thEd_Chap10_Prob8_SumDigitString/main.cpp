/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #8 Sum of Digits in a String
 * 
 * Problem: Write a program that asks the user to enter a series of single digit 
 * numbers with nothing separating them. Read the input as a C-string or a 
 * string object. The program should display the sum of all the single-digit 
 * numbers in the string. For example, if the user enters 2514, the program 
 * should display 12, which is the sum of 2, 5, 1, and 4. The program should 
 * also display the highest and lowest digits in the string.
 */

//System Libraries
#include <iostream>
#include <cstring>
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
    const int SIZE = 100;
    char num[SIZE];
    int total=0;
    
    //Input Values
    cout<<"Note: Maximum length is 100. Excess Input is ignored."<<endl<<endl;
    cout<<"Input Number: ";
    cin.getline(num, SIZE);
    
    //Process by mapping inputs to outputs
    int low=(num[0]-'0'), high=(num[0]-'0');
    
    for (int i=0;i<strlen(num); i++) {                  //Loop to get total and determine highest and lowest
        total+=(num[i]-'0');                            //digit in c-string array
        if ((num[i]-'0')<low) low=(num[i]-'0');         //Use ASCII Arithmetic to convert char to int
        if ((num[i]-'0')>high) high=(num[i]-'0');
    }
    
    //Output values
    cout<<"\nTotal: "<<total<<endl;
    cout<<"Highest: "<<high<<endl;
    cout<<"Lowest: "<<low<<endl;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}