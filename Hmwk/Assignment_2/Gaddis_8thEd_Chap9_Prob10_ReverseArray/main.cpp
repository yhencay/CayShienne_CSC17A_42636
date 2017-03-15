/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 13, 2017, 8:38 PM
 * Purpose: Homework Reverse Array
 * 
 *      Problem: Write a function that accepts an int array and the array’s size 
 *          as arguments. The function should create a copy of the array, except 
 *          that the element values should be reversed in the copy. The function 
 *          should return a pointer to the new array. Demonstrate the function 
 *          in a complete program.
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
int *copyRev(int *, int);   //Reversed copy of array
void pntAry(int *, int);   //Print Array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int num, *array = nullptr, *copy = nullptr;
    
    cout<<"Number of Elements to Allocate: ";
    cin>>num;
    cout<<"\nGenerating "<<num<<" random numbers from 10-99..."<<endl;
    
    //Input Values
    //Process by mapping inputs to outputs
    array = alloc8(num);
    
    //Output values
    pntAry(array, num);
    copy=copyRev(array, num);
    pntAry(copy, num);
    
    delete [] array;
    delete [] copy;
    array = 0;
    copy = 0;
     
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

//************************** Display Array Function *****************************
//Description: Display pointer array
//Inputs:   No inputs but utilizes integer argument and size
//Outputs:  The whole array of integer
//******************************************************************************

void pntAry(int *a, int n) {
    cout<<endl;
    for (int c=0; c<n; c++) {
        cout<<*(a+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
}

//******************************* Copy Function ********************************
//Description: Reverse copy of array integers (not sorted)
//Inputs:   No inputs but utilizes integer argument and size
//Outputs:  Returns pointer to array
//******************************************************************************

int *copyRev(int *a, int n) {
    int *copy=nullptr, j=n;     //copy pointer, count
    copy=new int[n];
    for (int i=0; j>0; j--, i++) {
       *(copy+i)=*(a+(j-1));        
    }
    return copy;
}
