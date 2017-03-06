
/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on MKarch 5, 2017, 7:35 AM
 * Purpose: Homework Color Mixer
 * 
 *      Problem: The colors red, blue, and yellow are known as the primary 
 * colors because they cannot be made by mixing other colors. When you mix two 
 * primary colors, you get a secondary color, as shown here:
 *          When you mix red and blue, you get purple.
 *          When you mix red and yellow, you get orange.
 *          When you mix blue and yellow, you get green.
 *      Write a program that prompts the user to enter the names of two primary 
 * colors to mix. If the user enters anything other than “red,” “blue,” or 
 * “yellow,” the program should display an error message. Otherwise, the program 
 * should display the name of the secondary color that results by mixing two 
 * primary colors.
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
    string frsCol,              //First Color input
           scnCol,              //Second color input
           red = "red",         //Color to mix (red)
           blue = "blue",       //Color to mix (blue)
           yellow = "yellow",   //Color to mix (yellow)
           result;              //Result of the mixed colors
    
    //Input Values
    cout<<"Let's mix together primary colors (red, blue, yellow)."<<endl
        <<"You only get a secondary color when you mix two colors from above.\n"
        <<"If you enter other colors beside those three, you get an error!\n"
        <<"\nReminder: When you type, it must be in lowercase or you get an error."
        <<endl<<endl;
    cout<<"1st Color: ";
    cin>>frsCol;                    //Prompt user for input
    
    cout<<"2nd Color: ";
    cin>>scnCol;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    //Output values  
    if (frsCol == "red") {
        if (scnCol == "blue"){
            cout<<"After mixing red and blue, you get a purple!\n";
        }
        else if (scnCol == "yellow") {
            cout<<"After mixing red and yellow, you get an orange!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else if (frsCol == "blue") {
        if (scnCol == "red"){
            cout<<"After mixing blue and red, you get a purple!\n";
        }
        else if (scnCol == "yellow") {
            cout<<"After mixing blue and yellow, you get a green!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else if (frsCol == "yellow") {
        if (scnCol == "red"){
            cout<<"After mixing yellow and red, you get an orange!\n";
        }
        else if (scnCol == "blue") {
            cout<<"After mixing yellow and blue, you get green!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else {
        cout<<"INVALID INPUT!";
    }
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

