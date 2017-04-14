/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 3, 2017, 9:20 PM
 * Purpose: Homework #4 Line Numbers
 * 
 * Problem: (This assignment could be done as a modification of the program in 
 * Programming Challenge 2.) Write a program that asks the user for the name of 
 * a file. The program should display the contents of the file on the screen. 
 * Each line of screen output should be preceded with a line number, followed 
 * by a colon. The line numbering should start at 1.
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
    string fylName, hold;
    int cnt=0;
    char press='\0';
	
    //Input Values
    cout<<"Choose file to open:"<<endl<<endl;
    cout<<"- One\n- Two\n- Three\n"<<endl;
    cout<<"CHOICE: ";
    cin>>fylName;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    fstream file;
    file.open(fylName+".txt", ios::in);
    if(file) {
        while(file) {
            getline(file, hold);
            cnt++;
        }
        cnt--;
    file.close();
    
    //Output Values
    file.open(fylName+".txt", ios::in);
        for (int i=0;i<cnt;i++) {
            getline(file, hold);
            cout<<i+1<<": "<<hold<<endl;
            if ((i+1)%24==0) {
                cout<<"\nPress enter key to continue!"<<endl<<endl;
                cin.get(press);
                cin.ignore(256, '\n');
                cin.clear();
            }
        }
    file.close();
    }
    
    else {
        cout<<"\nERROR! File does not exist!"<<endl<<endl;
    }
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}