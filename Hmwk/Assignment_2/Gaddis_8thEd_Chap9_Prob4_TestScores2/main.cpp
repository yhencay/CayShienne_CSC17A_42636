/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 9, 2017, 11:29 AM
 * Purpose: Homework Test Scores 2
 * 
 *      Problem: Modify the program of Programming Challenge 2 to allow the user
 *           to enter name-score pairs. For each student taking a test, the user 
 *           types the student’s name followed by the student’s integer test 
 *           score. Modify the sorting function so it takes an array holding the
 *           student names and an array holding the student test scores. When 
 *           the sorted list of scores is displayed, each student’s name should 
 *           be displayed along with his or her score. In stepping through the 
 *           arrays, use pointers rather than array subscripts. 
 */

//System Libraries
#include <iostream>     //Input Output Library
#include <string>       //String Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void srtAryS(float *, string *, int);       //Sort array function
void shwAry(float *, string *, int);       //Display array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int numTest;
    float average;
    string dummy;       //Dummy string for getline
    
    //Input Values
    cout<<"Enter number of students: ";
    cin>>numTest;
    cout<<endl;
    getline(cin, dummy);
    
    float *tests = nullptr;
    string *student = nullptr;
    
    tests = new float[numTest];
    student = new string[numTest];
    
    for (int c=0; c<numTest; c++) {
        cout<<"Student Name: ";
        getline(cin, student[c]);
        do {
            cout<<"Test Score: ";
            cin>>tests[c];
            getline(cin, dummy);
            if (tests[c]<0) cout<<"\nInvalid Input!"<<endl<<endl;
        } while (tests[c]<0);   //Invalidate if score is less than 0
        cout<<endl;
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    srtAryS(tests, student, numTest);
    
    //Output values
    shwAry(tests, student, numTest);
    
    delete [] tests;
    delete [] student;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//**************************** Sort Array Function *****************************
//Description: Sorts array with name equivalent to score
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAryS(float *t, string *stud, int s) {
    float temp; string temp2;
    for (int i=0; i<s-1; i++) {
        for (int c=i+1; c<s; c++) {
            if (t[i]>t[c]) {
                temp = t[i];
                t[i] = t[c];
                t[c] = temp;
                temp2 = stud[i];
                stud[i] = stud[c];
                stud[c] = temp2;
            }
        }
    }
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array with names equivalent with score
//******************************************************************************

void shwAry(float *t, string *stud, int s) {
    for (int c=0; c<s; c++) {
        cout<<*(stud+c)<<"\t"<<*(t+c)<<endl;
    }
}