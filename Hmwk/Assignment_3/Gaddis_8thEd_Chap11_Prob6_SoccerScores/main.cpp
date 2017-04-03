/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 29, 2017, 12:50 PM
 * Purpose:  Homework # 4 Weather Statistics
 * 
 * Problem: Write a program that stores the following data about a soccer player
 *       in a structure:
 *              Player’s Name
 *              Player’s Number
 *              Points Scored by Player
 *      The program should keep an array of 12 of these structures. Each element 
 *    is for a different player on a team. When the program runs it should ask 
 *    the user to enter the data for each player. It should then show a table 
 *    that lists each player’s number, name, and points scored. The program 
 *    should also calculate and display the total points earned by the team. The 
 *    number and name of the player who has earned the most points should also 
 *    be displayed.
 *          Input Validation: Do not accept negative values for players’ numbers 
 *                  or points scored.
 */

//System Libraries Here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Soccer.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
SoccerS *plyFill(int);
void destroy(SoccerS *);
short totPnts(SoccerS *, int);
void hiest(SoccerS *, int);
void dsPlyrs(SoccerS *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=12;    
    SoccerS *plyrs=plyFill(size);
    short total=totPnts(plyrs, size);
    
    //Output the created array
    dsPlyrs(plyrs, size);
    
    destroy(plyrs);
    //Display data
    
    //Exit
    return 0;
}

SoccerS *plyFill(int s) {
    SoccerS *a=new SoccerS;
    a->name=new string[s];
    a->number=new short[s];
    a->points=new short[s];
    string dummy;
    for (int c=0;c<s;c++) {
        cout<<"\nPlayer "<<c+1<<endl<<endl;
        cout<<"Player Name: ";
        getline(cin, a->name[c]);
        
        cout<<"Player Number: ";
        cin>>a->number[c];
        cin.ignore(256, '\n');
        while(cin.fail()||(a->number[c]<0)) {
            cout<<"\nNo negative values allowed!"<<endl<<endl;
            cout<<"Player Number: ";
            cin.clear();
            cin>>a->number[c];
        }
        cout<<"Points Scored by Player: ";
        cin>>a->points[c];
        cin.ignore(256, '\n');
      //  getline(cin, dummy);
        while(cin.fail()||(a->points[c]<0)){
            cout<<"\nNo negative values allowed!"<<endl<<endl;
            cout<<"Points Scored by Player: ";
            cin.clear();
         //   getline(cin, dummy);
            cin>>a->points[c];
        }
        
    }
    return a;
}

void hiest(SoccerS *p, int s) {
    short hiest=0, cntH; string hi;
    for (int i=0;i<s;i++) {
        if ((p->points[i])>hiest) {
            hiest=p->points[i];
            cntH=i;
        }
    }
    cout<<"Highest Score: "<<hiest<<", "<<p->name[cntH]<<endl;
} 

void destroy(SoccerS *p) {
    delete []p->points;
    delete []p->number;
    delete []p->name;
    delete p;
}

short totPnts(SoccerS *p, int s) {
    short total=0;
    for (int i=0;i<s;i++) {
        total+=p->points[i];
    }
    return total;
}

void dsPlyrs(SoccerS *p, int s) {
    cout<<endl;
    cout<<"\t\tNAME\t  Number      Points"<<endl<<endl;
    for(int c=0;c<s;c++) {
        cout<<setw(20)<<p->name[c]<<setw(12)<<p->number[c]<<setw(12)<<p->points[c]<<endl;
    }
    cout<<endl;
    hiest(p, s);
}
