/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 3, 2017, 9:20 PM
 * Purpose: Homework #3 Punch Line
 * 
 * Problem: Write a program that reads and prints a joke and its punch line from 
 *      two different files. The first file contains a joke, but not its punch 
 *      line. The second file has the punch line as its last line, preceded by 
 *      “garbage.” The main function of your program should open the two files 
 *      and then call two functions, passing each one the file it needs. The 
 *      first function should read and display each line in the file it is 
 *      passed (the joke file). The second function should display only the last 
 *      line of the file it is passed (the punch line file). It should find this 
 *      line by seeking to the end of the file and then backing up to the 
 *      beginning of the last line. Data to test your program can be found in 
 *      the joke.txt and punchline.txt files.
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
    fstream joke;
    fstream punch;
    string hold="", still="", word="";
    char sp='\0';
    
    //Input Values
    joke.open("joke.txt", ios::in);
    while (joke){
        getline(joke, still);
        cout<<still<<endl; //output the string
    }
    
    //Process by mapping inputs to outputs
    cout<<"Press enter twice to continue!"<<endl; //pause for timing
    cin.ignore(256, '\n'); 
    cin.get();
    
    //Output values
    punch.open("punchline.txt", ios::in);
    for (int i=1; sp!='\n'; i++) {
        punch.seekg(-i, ios::end);
        punch.get(sp);
    }
    getline(punch, word);
    cout<<word<<endl;
    
    joke.close();
    punch.close();
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}