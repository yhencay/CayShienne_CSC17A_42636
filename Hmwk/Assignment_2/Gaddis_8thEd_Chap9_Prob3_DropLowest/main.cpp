/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 9, 2017, 11:30 AM
 * Purpose: Homework Drop Lowest Score
 * 
 *      Problem: Modify Problem 2 above so the lowest test score is dropped. 
 *          This score should not be included in the calculation of the average. 
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
float calAve(float *, int);    //Calculate average function
void shwAry(float *, int);     //Display Array

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
    cout<<*(tests+0)<<" - Lowest Score is dropped!"<<endl<<endl;
    
    average = calAve(tests, numTest);
    
    //Output values
    shwAry(tests, numTest);
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
//Description: Count average dropping lowest score
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Returns float average
//******************************************************************************

float calAve(float *t, int s) {
    float ave = 0;
    for (int c=1; c<s; c++) {
        ave+=*(t+c);
    }
    ave/=(s-1);
    return ave;
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array
//******************************************************************************

void shwAry(float *t, int s) {
    for (int c=1; c<s; c++) {
        cout<<*(t+c)<<endl;
    }
}