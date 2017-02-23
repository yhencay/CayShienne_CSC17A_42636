/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 3:13 PM
 * Purpose: Homework 4.10
 * 
 * Problem: Write an if statement that performs the following logic: if the 
 *      variable sales is greater than 50,000, then assign 0.25 to the 
 *      commissionRate variable, and assign 250 to the bonus variable.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const short PERCENT = 100;

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float sales, cmshnr8 = 0, bonus = 0;

    //Input Values
    cout<<"Input Sales: ";
    cin>>sales;
    
    //Process by mapping inputs to outputs
    if (sales>50000) {
        cmshnr8 = 0.25f;
        bonus = 250;
    }
    
    //Output values    
    cout<<"\nCommission Rate: "<<cmshnr8*PERCENT<<"%"<<endl;
    cout<<"Bonus: "<<bonus<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}