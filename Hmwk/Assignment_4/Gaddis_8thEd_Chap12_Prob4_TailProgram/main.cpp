/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 1, 2017, 9:20 PM
 * Purpose: Homework #4 Tail Program
 * 
 * Problem: Write a program that asks the user for the name of a file. The 
 * program should display the last 10 lines of the file on the screen (the 
 * “tail” of the file). If the file has fewer than 10 lines, the entire file 
 * should be displayed, with a message indicating the entire file has been 
 * displayed.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
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
    string hold, still; 
    int cnt=0;
    
    //Input Values
    fstream file;
    file.open("data.txt", ios::in);
    
    //Process by mapping inputs to outputs
    while(file) {
        getline(file, hold);
        cnt++;
    }
    cnt--;
    file.close();
    
    //Output values
    file.open("data.txt", ios::in);
    if (cnt<10) {
        cout<<"Displaying "<<cnt<<" lines of a file!"<<endl<<endl;
        for (int i=0; i<cnt; i++) {
            getline(file, still);
            cout<<still<<endl;
        }
        cout<<"\nThe content has less than ten lines!"<<endl;
    }
    else {
        cout<<"Displaying the last 10 lines from file!"<<endl<<endl;
        for (int i=0; i<cnt; i++) {
            if (i<(cnt-10)) {
                getline(file, still);
            }
            else {
                getline(file, still);
                cout<<still<<endl;
            }
        }
        cout<<"\nThe content has "<<cnt<<" lines total!"<<endl;
    }
    file.close();
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}