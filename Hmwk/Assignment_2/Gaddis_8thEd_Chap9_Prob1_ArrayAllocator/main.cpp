/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 7, 2017, 8:38 PM
 * Purpose: Homework Array Allocator
 * 
 *      Problem: Write a function that dynamically allocates an array of 
 *          integers. The function should accept an integer argument indicating 
 *          the number of elements to allocate. The function should return a 
 *          pointer to the array.
 */

//System Libraries
#include <iostream> //Input Output Library
#include <cstdlib> //Standard Library
#include <ctime>  //Time Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int *alloc8(int);   //Function to allocate memory

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int num, *array = nullptr;
    
    cout<<"Number of Elements to Allocate: ";
    cin>>num;
    cout<<"\nGenerating "<<num<<" random numbers from 10-99..."<<endl<<endl;
    
    //Input Values
    //Process by mapping inputs to outputs
    array = alloc8(num);
    
    //Output values
    for (int c=0; c<num; c++) {
        cout<<*(array+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
    
    delete [] array;
    array = 0;
     
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//******************** Dynamic Memory Allocation Function **********************
//Description: Allocate array of integers
//Inputs:   No inputs but utilizes integer argument
//Outputs:  Returns pointer to array
//******************************************************************************

int *alloc8(int n) {
    int *arrPtr = nullptr;
    arrPtr = new int[n];
    for (int c=0; c<n; c++) {
        *(arrPtr+c)=rand()%90+10;     //Insert random number to array pointer
    }
    return arrPtr;
}