/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 21, 2017, 12:50 PM
 * Purpose:  Homework # 3 Corporate Sales Data
 * 
 * Problem: Write a program that uses a structure to store the following data 
 *      on a company division:
 *              Division Name (such as East, West, North, or South)
 *              First-Quarter Sales
 *              Second-Quarter Sales
 *              Third-Quarter Sales
 *              Fourth-Quarter Sales
 *              Total Annual Sales
 *              Average Quarterly Sales
 *      The program should use four variables of this structure. Each variable 
 *  should represent one of the following corporate divisions: East, West, 
 *  North, and South. The user should be asked for the four quarters’ sales 
 *  figures for each division. Each division’s total and average sales should be 
 *  calculated and stored in the appropriate member of each structure variable. 
 *  These figures should then be displayed on the screen.
 *          Input Validation: Do not accept negative numbers for any sales 
 *                      figures.
 */

//System Libraries Here
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries Here
#include "SlsData.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void filSls(SlsData &);     //Fill Sales Data
void slsDis(SlsData);       //Sales Display

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    SlsData northD = {"North Division"};
    SlsData eastD = {"East Division"};
    SlsData westD = {"West Division"};
    SlsData southD = {"South Division"};
    
    //Output the created array
    filSls(northD);
    filSls(eastD);
    filSls(westD);
    filSls(southD);
    
    //Display data
    cout<<"\t    REPORT"<<endl;
    slsDis(northD);
    slsDis(eastD);
    slsDis(westD);
    slsDis(southD);
    
    //Exit
    return 0;
}

void filSls(SlsData &region) {
    cout<<"Enter Data for "<<region.name<<endl<<endl;
    cout<<"1st Quarter Sales: $";
    cin>>region.first;
    while(cin.fail()||(region.first<0)) {
        cout<<"\nYou must only enter a number greater than 0!"<<endl<<endl;
        cout<<"1st Quarter Sales: $";
        cin.clear();
        cin.ignore(256, '\n');
        cin>>region.first;
    }
    cout<<"2nd Quarter Sales: $";
    cin>>region.second;
    while(cin.fail()||(region.second<0)) {
        cout<<"\nYou must only enter a number greater than 0!"<<endl<<endl;
        cout<<"2nd Quarter Sales: $";
        cin.clear();
        cin.ignore(256, '\n');
        cin>>region.second;
    }
    cout<<"3rd Quarter Sales: $";
    cin>>region.third;
    while(cin.fail()||(region.third<0)) {
        cout<<"\nYou must only enter a number greater than 0!"<<endl<<endl;
        cout<<"3rd Quarter Sales: $";
        cin.clear();
        cin.ignore(256, '\n');
        cin>>region.third;
    }
    cout<<"4th Quarter Sales: $";
    cin>>region.fourth;
    while(cin.fail()||(region.fourth<0)) {
        cout<<"\nYou must only enter a number greater than 0!"<<endl<<endl;
        cout<<"4th Quarter Sales: $";
        cin.clear();
        cin.ignore(256, '\n');
        cin>>region.fourth;
    }
    region.total=(region.first)+(region.second)+(region.third)+(region.fourth);
    region.ave=(region.total)/4;
    cout<<endl;
}

void slsDis(SlsData region) {
    cout<<endl;
    cout<<"\t"<<region.name<<endl<<endl;
    cout<<"1st Quarter Sales:        $ "<<region.first<<endl;
    cout<<"2nd Quarter Sales:        $ "<<region.second<<endl;
    cout<<"3rd Quarter Sales:        $ "<<region.third<<endl;
    cout<<"4th Quarter Sales:        $ "<<region.fourth<<endl<<endl;
    cout<<"Total Annual Sales:       $ "<<region.total<<endl;
    cout<<"Average Quarterly Sales:  $ "<<region.ave<<endl;
}
