/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #3 Word Counter
 * 
 * Problem: Write a function that accepts a pointer to a C-string as an argument 
 * and returns the number of words contained in the string. For instance, if the 
 * string argument is “Four score and seven years ago” the function should return 
 * the number 6. Demonstrate the function in a program that asks the user to 
 * input a string and then passes it to the function. The number of words in the 
 * string should be displayed on the screen. Optional Exercise: Write an 
 * overloaded version of this function that accepts a string class object as its 
 * argument.
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
short wrdChar(char *, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 80;
    char input[SIZE];
    short numWrd;
    
    //Input Values
    cout<<"Enter 1-79 number of characters. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: We will calculate how many words there are."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);
    
    //Process by mapping inputs to outputs
    numWrd = wrdChar(input, SIZE);
    
    //Output values
    cout<<"\nWord Count: "<<numWrd<<" word(s)"<<endl<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//**************************** Word Count Function *****************************
//Description: Counts how many words are the in a C-string array
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Number of words in a C-string array
//******************************************************************************

short wrdChar(char *i, int s) {
    short cnt=0;
    for (int c=0; c<s && i[c]!='\0'; c++) {
        if (i[c]==' ') cnt++;
    }
    if (i[0]=='\0') cnt=0;
    else cnt+=1;
    return cnt;
}