/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 5, 2017,  9:29 PM
 * Purpose: Homework Math Tutor
 *      Problem: Write a program that can be used as a math tutor for a young 
 * student. The program should display two random numbers to be added, such as 
 *       247
 *     +129
 * The program should then pause while the student works on the problem. When 
 * the student is ready to check the answer, he or she can press a key and the 
 * program will display the correct solution:
 *       247
 *     +129
 *       376
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
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
    srand(static_cast<unsigned int>(time(0)));
    unsigned short fadd, sadd;                  //First Addend & Second Addend
    int sum;
        
    //Input Values
    fadd = (rand()%(65535-1+1))+1;              //Both are datatype short range!
    sadd = (rand()%(65535-1+1))+1;
    
    //Process by mapping inputs to outputs
    sum = fadd + sadd;
    //Output values
    cout<<"Try to solve!"<<endl<<endl;
    cout<<"            "<<setw(5)<<fadd<<endl;
    cout<<"          + "<<setw(5)<<sadd<<endl
        <<"           -------"<<endl<<endl;
    cout<<"Press enter for full answer!";
    cin.get();
    cout<<endl;
    cout<<"            "<<setw(5)<<fadd<<endl;
    cout<<"          + "<<setw(5)<<sadd<<endl; 
    cout<<"           -------"<<endl;
    cout<<"  Answer:   "<<setw(5)<<sum<<endl;
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

