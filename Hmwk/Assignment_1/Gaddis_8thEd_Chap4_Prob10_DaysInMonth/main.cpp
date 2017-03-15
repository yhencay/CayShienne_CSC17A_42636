/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 2, 2017, 11:40 AM
 * Purpose: Homework 
 * 
 *      Problem: Write a program that asks the user to enter the month (letting 
 *          the user enter an integer in the range of 1 through 12) and the 
 *          year. The program should then display the number of days in that 
 *          month. Use the following criteria to identify leap years: 
 *              1. Determine whether the year is divisible by 100. If it is, 
 *              then it is a leap year if and only if it is divisible by 400. 
 *                  For example, 2000 is a leap year but 2100 is not.
 *              2. If the year is not divisible by 100, then it is a leap year 
 *              if and if only it is divisible by 4. For example, 2008 is a 
 *              leap year but 2009 is not.
 * 
 *          Here is a sample run of the program:
 * 
 *              Enter a month (1-12): 2 [ Enter]
 *              Enter a year: 2008 [Enter]
 *              29 days
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

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int year;
    unsigned short month;
    
    //Input Values
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";             //Prompt user for input
    cin>>year;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    //Output values
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) cout<<"31 Days"<<endl;      //Normal days
    else if (month==4||month==6||month==9||month==11) cout<<"30 Days"<<endl;
    else if (month==2) {
        if (year%100==0&&year%400==0) cout<<"29 Days"<<endl;            //Determine leap years
        else if (!(year%100==0)&&year%4==0) cout<<"29 Days"<<endl;
        else cout<<"28 Days"<<endl;
    }  
    else cout<<"Invalid Input!"<<endl;          //Month has to be 1-12
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}