/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 6, 2017, 9:20 PM
 * Purpose: Homework #3 Car Class
 * 
 * Problem: Write a class named Car that has the following member variables:
 *              • yearModel . An int that holds the car’s year model.
 *              • make . A string that holds the make of the car.
 *              • speed . An int that holds the car’s current speed.
 *  In addition, the class should have the following constructor and other 
 *  member functions.
 *      • Constructor. The constructor should accept the car’s year model and 
 *        make as arguments. These values should be assigned to the object’s 
 *        yearModel and make member variables. The constructor should also 
 *        assign 0 to the speed member variables.
 *      • Accessor. Appropriate accessor functions to get the values stored in 
 *        an object’s yearModel , make , and speed member variables.
 *      • accelerate . The accelerate function should add 5 to the speed member 
 *        variable each time it is called.
 *      • brake . The brake function should subtract 5 from the speed member 
 *        variable each time it is called.
 *  Demonstrate the class in a program that creates a Car object, and then calls 
 *  the accelerate function five times. After each call to the accelerate 
 *  function, get the current speed of the car and display it. Then, call the 
 *  brake function five times. After each call to the brake function, get the 
 *  current speed of the car and display it.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "Cars.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int yr;
    string m;
    
    //Input Values
    cout<<"Car Make: ";
    getline(cin, m);
    cout<<"Year Model: ";
    cin>>yr;  
    
    //Process by mapping inputs to outputs
    Car data(yr, m);
    
    //Output values
    cout<<endl<<endl<<"Information"<<endl<<endl;
    cout<<"Car: "<<data.getMake()<<endl;
    cout<<"Year Model: "<<data.getYr()<<endl;
    cout<<"Speed: "<<data.getSpd()<<" mph"<<endl<<endl;
    cout<<"Press ENTER to start accelerating!"<<endl;
    cin.ignore(256, '\n');
    cin.get();
    
    for (int i=0; i<5; i++) {
        data.axlr8();
        cout<<"Current Speed: "<<data.getSpd()<<" mph"<<endl;
    }
    
    cout<<"\nPress ENTER to start braking!"<<endl;
    cin.get();
    
    for (int i=0; i<5; i++) {
        data.brake();
        cout<<"Current Speed: "<<data.getSpd()<<" mph"<<endl;
    }
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}