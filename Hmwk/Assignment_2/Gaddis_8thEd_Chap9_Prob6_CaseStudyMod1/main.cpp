/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 14, 2017, 8:38 PM
 * Purpose: Homework Case Study Modification 1
 * 
 *      Problem: Modify Program 9-19 (the United Cause case study program) so it 
 *          can be used with any set of donations. The program should dynamically 
 *          allocate the donations array and ask the user to input its values.
 */

//System Libraries
#include <iostream> //Input Output Library
#include <cstdlib>  //C Standard Library
#include <ctime>    //Time Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
float *donFill(int);      //Manually fill array
void srtAryA(float *, int);    //Sort array
void prntAry(float *, int);   //Display array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float *donate = nullptr;  
    int size;
    char choice; 
    bool x=true;
    
    cout<<"Number of set donations: ";
    cin>>size;
    
    //Input Values
    donate = donFill(size);
    
    //Process by mapping inputs to outputs
    srtAryA(donate, size);
    
    //Output values
    cout<<endl<<"The donations sorted in ascending order: "<<endl;
    prntAry(donate, size);
    
    delete [] donate;
    donate = 0;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//************************ Donation Fill Function ******************************
//Description: Manually Fill Array with donation's of user's input
//Inputs:   Input integer numbers based on input size
//Outputs:  Returns a pointer
//******************************************************************************

float *donFill(int s) {
    float *d = nullptr;       //Donated
    d = new float[s];
    cout<<endl;
    for (int c=0; c<s; c++) {
        cout<<"Amount "<<c+1<<": $ ";
        cin>>*(d+c);
    }
    return d;
}

//***************************** Sort Function **********************************
//Description: Sort array ascending order
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAryA(float *a, int n) {
    float temp;
    for(int c=0;c<n-1;c++){
        for(int i=c+1;i<n;i++){
            if(*(a+c)>*(a+i)){
                temp = *(a+c);
                *(a+c) = *(a+i);
                *(a+i) = temp;
            }
        }        
    }
}

//***************************** Display Function *******************************
//Description: Display and output array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Pointer Array values
//******************************************************************************

void prntAry(float *a, int s) {
    cout<<endl;
    for (int c=0; c<s; c++) {
        cout<<c+1<<".  "<<*(a+c)<<" "<<endl;
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
}

