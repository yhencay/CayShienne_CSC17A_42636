/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #
 * 
 * Problem: 
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "NumDays.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float hrs1, hrs2;
    NumDay frst;
    NumDay scnd;
    
    //Input Values
    cout<<"1st Enter Hours: ";
    cin>>hrs1;
    
    cout<<"2nd Enter Hours: ";
    cin>>hrs2;    
    
    //Process by mapping inputs to outputs
    frst.setHour(hrs1);
    scnd.setHour(hrs2);
    
    //Output values
    cout<<endl<<"1. Hours: "<<frst.getHour()<<" hours\t Day: "<<frst.getDay()<<" days";
    cout<<endl<<"2. Hours: "<<scnd.getHour()<<" hours\t Day: "<<scnd.getDay()<<" days";
    cout<<endl<<endl<<"Addition Operator: "<<frst.operator +(scnd.getHour())<<" hours";
    cout<<endl<<"Subtraction Operator: ";
    if (scnd.getHour()>frst.getHour()) {
        cout<<scnd.operator -(frst.getHour())<<" hours";
    }
    else if (frst.getHour()>scnd.getHour()) {
        cout<<frst.operator -(scnd.getHour())<<" hours";
    }
    cout<<endl<<endl<<"First Increment Operator "<<endl<<endl;
    cout<<"Postfix: "<<frst.operator ++(hrs1)<<" hours\t = "<<frst.getDay()<<" days"<<endl;
    cout<<"Prefix: "<<frst.operator ++()<<" hours\t = "<<frst.getDay()<<" days"<<endl<<endl;
    cout<<"Second Decrement Operator "<<endl<<endl;
    cout<<"Postfix: "<<scnd.operator ++(hrs2)<<" hours\t = "<<scnd.getDay()<<" days"<<endl;
    cout<<"Prefix: "<<scnd.operator ++()<<" hours\t = "<<scnd.getDay()<<" days"<<endl<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}