/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 21, 2017, 12:50 PM
 * Purpose:  Homework # 2 Movie Data
 * 
 * Problem: Modify the Movie Data program written for Programming Challenge 1 to 
 *      include two additional members that hold the movie’s production costs 
 *      and first-year revenues. Modify the function that displays the movie 
 *      data to display the title, director, release year, running time, and 
 *      first year’s profit or loss. 
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
void shwData(MovData, float);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    MovData data;
    float winLos, equal=0;
    
    filData(data);
    
    winLos = (data.profit>data.cost)?data.profit-data.cost:
             (data.profit<data.cost)?data.cost-data.profit:equal;
    
    shwData(data, winLos);
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
    cout<<"Production Cost: $";
    cin>>data.cost; 
    cout<<"First-Year Revenue: $";
    cin>>data.profit;
    cout<<endl;
}

void shwData(MovData data, float winLos) {
    cout<<"\nYour Input: \t\t"<<endl<<endl;
    cout<<"Movie Title: \t\t"<<data.title<<endl;
    cout<<"Director: \t\t"<<data.direct<<endl;
    cout<<"Year Released: \t\t"<<data.year<<endl;
    cout<<"Running Time \n(in minutes): \t\t"<<data.runtime<<" minutes"<<endl;
    cout<<"Production Cost: \t$"<<data.cost<<endl;
    if (data.profit>data.cost) cout<<"Profit: \t\t$"<<winLos<<endl;
    else if (data.profit<data.cost) cout<<"Loss: \t\t$"<<winLos<<endl;
    else cout<<"\nNo Profit or Loss!"<<endl;
    cout<<endl;
}