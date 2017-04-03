/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #4 Average Number of Letters
 * 
 * Problem: Modify the program you wrote for Problem 3 (Word Counter), so it 
 * also displays the average number of letters in each word.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
short wrdChar(char *, int);
short cntChar(char *, int );

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 80;
    char input[SIZE];
    float ave;
    short numWrd, numChar;
    
    //Input Values
    cout<<"Enter 1-79 number of characters including spaces. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: We will calculate the average number of letters (excluding spaces)."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);
    
    //Process by mapping inputs to outputs
    numChar = cntChar(input, SIZE);
    numWrd = wrdChar(input, SIZE);
    ave = (static_cast<float>(numChar)/numWrd);
    
    //Output values
    cout<<"\nCharacter Count: "<<numChar<<" character(s)"<<endl;
    cout<<"Word Count: "<<numWrd<<" word(s)"<<endl<<setprecision(3);
    cout<<"Average Number of Letters: "<<ave<<" letter(s) per word"<<endl<<endl;
        
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

//************************** Count Strings Function ****************************
//Description: Counts how many number of characters in a character array
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Length of characters in an input
//******************************************************************************

short cntChar(char *a, int s) {
    short cnt=0;
    for (int i=0; i<s && a[i]!='\0'; i++) {
        cnt++;
        if (a[i]==' ') cnt--;
    }
    if (a[0]=='\0') cnt=0;
    return cnt;
}