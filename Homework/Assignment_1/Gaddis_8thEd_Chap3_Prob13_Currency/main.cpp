/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 2, 2017, 11:40 AM
 * Purpose: Homework 
 * 
 *      Problem: 
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
    const float yenPerD = 98.93f, euPerD = 0.74f;
    float dollar, yen, euro;
    
    //Input Values
    cout<<"Enter US Dollar Amount: $";
    cin>>dollar;
    
    yen = dollar*yenPerD;
    euro = dollar*euPerD;
    
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"\nUS DOLLAR:\t$"<<dollar<<endl<<endl;
    cout<<"YEN:\t "<<yen<<endl;
    cout<<"EURO:\t "<<euro<<endl;
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}