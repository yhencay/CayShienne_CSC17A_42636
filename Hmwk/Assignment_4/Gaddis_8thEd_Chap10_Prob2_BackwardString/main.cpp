/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #1 Backward String
 * 
 * Problem: Write a function that accepts a pointer to a C-string as an argument 
 * and displays its contents backward. For instance, if the string argument is 
 * “ Gravity ” the function should display “ ytivarG ”. Demonstrate the function 
 * in a program that asks the user to input a string and then passes it to the 
 * function.
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
void bckChar(char *, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 80;
    char data[SIZE];
    short numChar;
    
    //Input Values
    cout<<"Enter 1-79 number of characters. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: Data will be converted backwards."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(data, SIZE);
    
    //Process by mapping inputs to outputs

    //Output values
    cout<<"\nBackwards: ";
    bckChar(data, SIZE);
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//************************* Backward Output Function ***************************
//Description: Displays a user input C-string backwards
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Backward of the content array
//******************************************************************************

void bckChar(char *d, int s) {
    short cnt=0;
    for (int i=0; i<s && d[i]!='\0'; i++) {
        cnt++;
    }
    if (d[0]=='\0') cnt=0;
    for (int c=cnt; c>=0; c--) {
        cout<<*(d+c);
    }
    cout<<endl;
}