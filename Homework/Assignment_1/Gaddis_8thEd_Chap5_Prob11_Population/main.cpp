/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 3, 2017, 11:54 PM
 * Purpose: Homework Population
 * 
 *      Problem: Write a program that will predict the size of a population of 
 *          organisms. The program should ask the user for the starting number 
 *          of organisms, their average daily population increase (as a 
 *          percentage), and the number of days they will multiply. A loop
 *          should display the size of the population for each day. 
 *              Input Validation: Do not accept a number less than 2 for the 
 *                  starting size of the population.
 *          Do not accept a negative number for average daily population 
 *          increase. Do not accept a number less than 1 for the number of days 
 *          they will multiply.
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
const short PERCENT = 100; //Percentage Conversion

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    float ave, start;      //Average daily percentage, starting number
    int days;              //Days to multiply
    
    //Input Values
    cout<<"Input following: "<<endl<<endl;
    cout<<"Starting number of organisms: ";
    cin>>start;
    cout<<"Average daily population increase (percentage): ";
    cin>>ave;
    cout<<"Number of days they will multiply: ";
    cin>>days;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    ave=ave/PERCENT;        //Convert input to decimal
    
    //Output values
    if (start<2) cout<<"Starting number cannot be less than 2!"<<endl;                  //Input Validation
    else if (ave<0) cout<<"Daily population increase cannot be negative!"<<endl;
    else if (days<1) cout<<"Number of days to multiply cannot be less than 1!"<<endl;
    else {
        cout<<"Start  \t\t"<<start<<endl;
        cout<<setprecision(2)<<fixed<<showpoint;            //Loop for the program
        for (int c=0;c<days;c++) {                          //Calculates organisms and displays
            start+=start*ave;                               //how much they grow
            cout<<"Day "<<c+1<<"\t\t"<<start<<endl;
        }
    }
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}