/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 5, 2017, 7:38 PM
 * Purpose: Homework Binary String Search
 * 
 *      Problem: Modify the binarySearch function presented in this chapter so 
 *          it searches an array of strings instead of an array of int s. Test 
 *          the function with a driver program. Use Program 8-8 as a skeleton 
 *          to complete. (The array must be sorted before the binary search 
 *          will work.)
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
void disAry (string[], int);   //Display or Print Array
void rowSwap (string[], int);   //Swap a whole row for sorting
void sortAry (string[], int);   //Sort Array alphabetically

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int SIZE = 20;        //Size of array or number of names to initialize
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                          "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                          "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",        //Data input in array
                          "Looney, Joe", "Wolfe, Bill", "James, Jean",
                          "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                          "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                          "Pike, Gordon", "Hollan, Beth"};
    
    //Display Values
    cout<<"-------------------------"<<endl;
    cout<<"     Data from Array"<<endl;              //Display initial array
    cout<<"-------------------------"<<endl;
    disAry(names, SIZE);
    
    //Process by mapping inputs to outputs
    sortAry(names, SIZE);                       //Sort array using function
    
    //Output values
    cout<<"-------------------------"<<endl;
    cout<<"      Sorted Array"<<endl;                 //Display sorted array in alphabetical order
    cout<<"-------------------------"<<endl;
    disAry(names, SIZE);
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//**************************** Display Function ********************************
//Description: Display Array
//Inputs:   No inputs
//Outputs:  Displays array
//******************************************************************************

void disAry (string n[], int s) {
    cout<<"Number\tNames"<<endl;
    for (int c=0; c<s; c++) {
        cout<<setw(3)<<c+1<<"\t"<<n[c]<<endl;
    }
    cout<<endl;
}

//*************************** Row Swap Function ********************************
//Description: Swaps the whole row of a string input
//Inputs:   No inputs
//Outputs:  No outputs
//******************************************************************************

void rowSwap (string n[], int c) {
    string temp = ""; //string temp for swapping
    temp = n[c];      //assign current element to temp
    n[c] = n[c+1];    //change current element to next element
    n[c+1] = temp;    //change temp to current element that was changed
}

//*************************** Sort Array Function ******************************
//Description: Sort string array
//Inputs:   No inputs but utilizes array from main
//Outputs:  No outputs but sorts array
//******************************************************************************

void sortAry (string n[], int s) {
    bool swap;          
    do {
        swap = false;   //remains false if no swapped happened in loop
        for (int c=0; c<s-1; c++) {  
            if (n[c]>n[c+1]) {   //compare current element to next one
                rowSwap (n, c);  //if true, swap whole row by calling rowSwap function
                swap = true;     //keep swap true to continue loop
            }
        }
    } while (swap);
}