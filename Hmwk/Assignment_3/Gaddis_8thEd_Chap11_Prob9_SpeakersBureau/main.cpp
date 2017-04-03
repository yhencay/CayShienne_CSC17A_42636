/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 29, 2017, 12:50 PM
 * Purpose:  Homework # 4 Weather Statistics
 * 
 * Problem: Write a program that keeps track of a speakers’ bureau. The program 
 *      should use a structure to store the following data about a speaker:
 *              Name
 *              Telephone Number
 *              Speaking Topic
 *              Fee Required
 *      The program should use an array of at least 10 structures. It should let 
 *   the user enter data into the array, change the contents of any element, and 
 *   display all the data stored in the array. The program should have a 
 *   menu-driven user interface. 
 * 
 *          Input Validation: When the data for a new speaker is entered, be 
 *              sure the user enters data for all the fields. No negative 
 *              amounts should be entered for a speaker’s fee.
 */

//System Libraries Here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Speaker.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
Bureau *pplFill(int);
void destroy(Bureau *);
void disPlay(Bureau *, int);
void change(Bureau *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size; char choice; bool x=true;
    cout<<"How many speakers do you want to record (minimum is 10)? ";
    cin>>size;
    cin.ignore(256, '\n');
    Bureau *spkrs=pplFill(size);
    
    do {
        cout<<endl<<"What would you like to do?"<<endl<<endl;
        cout<<"Type 1 - Edit Contents in array"<<endl;
        cout<<"Type 2 - Display Data in array"<<endl<<endl;
        cout<<"Type 0 - EXIT"<<endl<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        
        switch (choice) {
            case 2: disPlay(spkrs, size);
            case 1: change(spkrs, size);
            case 0: x=false;
            default: cout<<"\nYou can only choose from the menu!"<<endl;
        }        
    } while (x);   
    
    destroy(spkrs);
    //Display data
    
    //Exit
    return 0;
}

Bureau *pplFill(int s) {
    Bureau *sp=new Bureau[s];
    sp->name=new string[s];
    sp->number=new int[s];
    sp->topic=new string[s];
    sp->fee=new float[s];
    for(int i=0;i<s;i++) {
        cout<<"Name: ";
        getline(cin, sp->name[i]);
        cout<<"Telephone Number: ";
        cin>>sp->number[i];
        cin.ignore(256, '\n');
        cout<<"Speaking Topic: ";
        getline(cin, sp->topic[i]);
        cin.ignore(256, '\n');
        cout<<"Fee Required: ";
        cin>>sp->fee[i];
        cin.ignore(256, '\n');
        while(cin.fail()||(sp->fee[i]<0)) {
            cout<<"\nNo negative values allowed!"<<endl<<endl;
            cout<<"Fee Required: ";
            cin.clear();
            cin>>sp->fee[i];
        }
    }
} 

void destroy(Bureau *s) {
    delete []s->name;
    delete []s->number;
    delete []s->topic;
    delete []s->fee;
    delete s;
}

void disPlay(Bureau *sp, int s) {
    cout<<"Number\t\tTelephone Number\tSpeaking Topic\tFee Required"<<endl;
    for(int c=0;c<s;c++) {
        cout<<c+1<<setw(20)<<sp->name[c]<<setw(12)<<sp->number[c]<<setw(20)
            <<sp->topic[c]<<setw(12)<<sp->fee[c]<<endl;
    }
}

void change(Bureau *sp, int s) {
    int ch;
    disPlay(sp, s);
    do {
        cout<<"\nChange what number? ";
        cin>>ch;
        if (ch>s||ch<0) cout<<"Number doesn't exist!"<<endl<<endl;
    } while (ch>s||ch<0);
    cout<<"Name: ";
    getline(cin, sp->name[ch]);
    cout<<"Telephone Number: ";
    cin>>sp->number[ch];
    cin.ignore(256, '\n');
    cout<<"Speaking Topic: ";
    getline(cin, sp->topic[ch]);
    cout<<"Fee Required: ";
    cin>>sp->fee[ch];
    cin.ignore(256, '\n');
    while(cin.fail()||(sp->fee[ch]<0)) {
        cout<<"\nNo negative values allowed!"<<endl<<endl;
        cout<<"Fee Required: ";
        cin.clear();
        cin>>sp->fee[ch];
    }
}
