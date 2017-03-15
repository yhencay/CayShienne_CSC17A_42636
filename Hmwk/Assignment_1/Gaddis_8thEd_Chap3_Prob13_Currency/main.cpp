/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 2, 2017, 11:40 AM
 * Purpose: Homework Currency
 * 
 *      Problem: Write a program that will convert U.S. dollar amounts to 
 *          Japanese yen and to euros, storing the conversion factors in the 
 *          constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR . To get the most 
 *          up-to-date exchange rates, search the Internet using the term 
 *          “currency exchange rate”. If you cannot find the most recent 
 *          exchange rates, use the following:
 *                  1 Dollar = 98.93 Yen
 *                  1 Dollar = 0.74 Euros
 *          Format your currency amounts in fixed-point notation, with two 
 *          decimal places of precision, and be sure the decimal point is 
 *          always displayed.
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
    const float yenPerD = 98.93f, euPerD = 0.74f;       //Conversion amount
    float dollar, yen, euro;                            //User input and variable to hold result
    
    //Input Values
    cout<<"Enter US Dollar Amount: $";
    cin>>dollar;                            //Prompt user for amount
    
    //Process by mapping inputs to outputs
    yen = dollar*yenPerD;                  
    euro = dollar*euPerD;
    
    //Output values
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"\nUS DOLLAR:\t$"<<dollar<<endl<<endl;
    cout<<"YEN:\t ¥"<<yen<<endl;                     //Display Results
    cout<<"EURO:\t €"<<euro<<endl;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}