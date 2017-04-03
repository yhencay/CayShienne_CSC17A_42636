/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 21, 2017, 12:50 PM
 * Purpose:  Homework # 1 Movie Data
 * 
 * Problem: Write a program that uses a structure named MovieData to store the 
 *      following information about a movie:
 *               Title
 *               Director
 *               Year Released
 *               Running Time (in minutes)
 *      The program should create two MovieData variables, store values in their 
 *      members, and pass each one, in turn, to a function that displays the 
 *      information about the movie in a clearly formatted manner. 
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "MovData.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void filData(MovData &);
void shwData(MovData);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    MovData data;
    
    filData(data);
    shwData(data);
    //Output the created array

    
    //Sort the array

    
    //Printout the sorted array


    //Delete the array

    
    //Exit
    return 0;
}

void filData(MovData &data) {
    string dummy;
    cout<<"Movie Title: ";
    getline(cin, data.title);
    cout<<"Director: ";
    getline(cin, data.direct);
    cout<<"Year Released: ";
    cin>>data.year;
    getline(cin, dummy);
    cout<<"Running Time (in minutes): ";
    cin>>data.runtime; 
    cout<<endl;
}

void shwData(MovData data) {
    cout<<"\nYour Input: \t"<<endl<<endl;
    cout<<"Movie Title: \t"<<data.title<<endl;
    cout<<"Director: \t"<<data.direct<<endl;
    cout<<"Year Released: \t"<<data.year<<endl;
    cout<<"Running Time \n(in minutes): \t"<<data.runtime<<" minutes"<<endl;
}