
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 5, 2017,  7:28 PM
 * Purpose: Homework Temperature Conversion
 * 
 *      Problem: Write a program that converts Celsius temperatures to 
 * Fahrenheit temperatures. The formula is F = ((9*C)/5)+32;
 *        F is the Fahrenheit temperature, and C is the Celsius temperature.
 */

//System Libraries
#include <iostream>
#include <iomanip>
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
    float tempC,
          tempF;
    
    //Input Values
    cout<<"Let's convert Celsius to Farenheit!"<<endl<<endl;
    cout<<"Input Celsius Temperature: ";
    cin>>tempC;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    tempF = ((9 * tempC)/5 )+ 32;
    
    //Output values
    cout<<fixed<<setprecision(1);
    cout<<"The temperature "<<tempC<<"°C is converted to "<<tempF<<"°F."<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

