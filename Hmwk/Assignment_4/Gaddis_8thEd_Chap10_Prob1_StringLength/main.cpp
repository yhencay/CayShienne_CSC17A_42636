/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #1 String Length
 * 
 * Problem: Write a function that returns an integer and accepts a pointer to a 
 * C-string as an argument. The function should count the number of characters 
 * in the string and return that number. Demonstrate the function in a simple 
 * program that asks the user to input a string, passes it to the function, and 
 * then displays the function’s return value.
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
short cntChar(char [], int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 80;
    char input[SIZE];
    short numChar;
    
    //Input Values
    cout<<"Enter 1-79 number of characters including spaces. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: Spaces are not counted in character count."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);
    
    //Process by mapping inputs to outputs
    numChar = cntChar(input, SIZE);
    
    //Output values
    cout<<"\nLength of character(s) entered: "<<numChar<<" character(s)"<<endl<<endl;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//************************** Count Strings Function ****************************
//Description: Counts how many number of characters in a character array
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Length of characters in an input
//******************************************************************************

short cntChar(char a[], int s) {
    short cnt=0;
    for (int i=0; i<s && a[i]!='\0'; i++) {
        cnt++;
        if (a[i]==' ') cnt--;
    }
    if (a[0]=='\0') cnt=0;
    return cnt;
}