/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 6, 2017, 9:20 PM
 * Purpose: Homework #4 Personal Info
 * 
 * Problem: Design a class that holds the following personal data: name, address, 
 *      age, and phone number. Write appropriate accessor and mutator functions. 
 *      Demonstrate the class by writing a program that creates three instances 
 *      of it. One instance should hold your information, and the other two 
 *      should hold your friends’ or family members’ information.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "InfoCls.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int entry, ch;
    bool x=true;
    
    //Input Values
    cout<<"How many entries do you want to input (including yourself)? ";
    cin>>entry;
    cin.ignore(256, '\n');
    PerInfo *data=new PerInfo[entry];
    
    //Process by mapping inputs to outputs
    for (int i=0; i<entry; i++) {
        cout<<"\nEntry #"<<i+1<<endl;
        data[i].setInfo();
    }
    
    //Output values
    do {
        cout<<"\nWhich entry would you like to view?"<<endl;
        cout<<"0 | QUIT"<<endl;
        for (int i=0; i<entry; i++) {
            cout<<i+1<<" | "<<data[i].getName()<<endl;
        }
        cout<<"\nCHOICE: ";
        cin>>ch;
        if (ch==0) x=false;
        else {
            ch-=1;
            if (ch<0||ch>=entry) cout<<"\nEntry does not exist!\n\n";
            else data[ch].disInfo();
        }
    } while(x);
        
    //Delete Pointer Array
    delete []data;
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}