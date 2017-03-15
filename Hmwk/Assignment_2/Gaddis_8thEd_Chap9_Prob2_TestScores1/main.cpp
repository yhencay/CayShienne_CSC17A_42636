/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 7, 2017, 9:20 PM
 * Purpose: Homework Test Scores 1
 * 
 *      Problem: Write a program that dynamically allocates an array large 
 *          enough to hold a user defined number of test scores. Once all the 
 *          scores are entered, the array should be passed to a function that 
 *          sorts them in ascending order. Another function should be called 
 *          that calculates the average score. The program should display the 
 *          sorted list of scores and averages with appropriate headings. Use 
 *          pointer notation rather than array notation whenever possible.
 * 
 *              Input Validation: Do not accept negative numbers for test 
 *                  scores.
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
void sortAry(float *, int);     //Sort array function
float calcAve(float *, int);    //Calculate average function
void showAry(float *, int);     //Display Array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int numTest;
    float average;
    
    //Input Values
    cout<<"Enter number of test scores: ";
    cin>>numTest;
    cout<<endl;
    
    float *tests = nullptr;
    tests = new float[numTest];
    
    for (int c=0; c<numTest; c++) {
        do {
            cout<<"Test "<<c+1<<": ";       //Input test scores
            cin>>*(tests+c);
            if (*(tests+c)<0) cout<<"\nInvalid Input!"<<endl<<endl;
        } while (*(tests+c)<0);               //Invalidate if less than 0
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    sortAry(tests, numTest);
    average = calcAve(tests, numTest);
    
    //Output values
    showAry(tests, numTest);
    cout<<"\nAverage: "<<average<<endl;
    
    delete [] tests;
    tests = 0;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//***************************** Sort Function **********************************
//Description: Sort array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void sortAry(float *t, int s) {
    float temp;
    for (int i=0; i<s-1; i++) {
        for (int c=i+1; c<s; c++) {
            if (*(t+i)>*(t+c)) {
                temp = *(t+i);
                *(t+i) = *(t+c);
                *(t+c) = temp;
            }
        }
    }
}

//*********************** Calculate Average Function ***************************
//Description: Count how many times an argument occurs in the array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Returns float average
//******************************************************************************

float calcAve(float *t, int s) {
    float ave = 0;
    for (int c=0; c<s; c++) {
        ave+=*(t+c);
    }
    ave/=s;
    return ave;
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array
//******************************************************************************

void showAry(float *t, int s) {
    for (int c=0; c<s; c++) {
        cout<<*(t+c)<<endl;
    }
}