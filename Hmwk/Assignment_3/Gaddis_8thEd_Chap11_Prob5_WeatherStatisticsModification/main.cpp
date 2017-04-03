/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 29, 2017, 12:50 PM
 * Purpose:  Homework # 4 Weather Statistics
 * 
 * Problem: Modify the program that you wrote for Programming Challenge 4 so it
 *       defines an enumerated data type with enumerators for the months 
 *       ( JANUARY , FEBRUARY , etc.). The program should use the enumerated 
 *       type to step through the elements of the array.
 */

//System Libraries Here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

//User Libraries Here
#include "Wstats.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
             SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

//Function Prototypes Here
WeaStat *wdrFill(int);
void fillWdr(WeaStat &);
void destroy(WeaStat *);
float totR(WeaStat *);
float rAve(WeaStat *);
float mAve(WeaStat *);
void hiloest(WeaStat *);
string month(int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    int size=12;    
    WeaStat *data=wdrFill(size);
    
    float yearRn=totR(data);
    float mAveRn=rAve(data);
    float mTemAve=mAve(data);
    
    //Output the created array
    cout<<endl;
    cout<<"Average Monthly Rainfall:  "<<mAveRn<<" inches"<<endl;
    cout<<"Total Rainfall of the Year:  "<<yearRn<<" inches"<<endl;
    hiloest(data);
    cout<<"Average of All Average Monthly Temperature:  "<<mTemAve<<" °F"<<endl;
    
    destroy(data);
    //Display data
    
    //Exit
    return 0;
}

WeaStat *wdrFill(int s) {
    WeaStat *a = new WeaStat;
    a->size=s;
    a->total=new float[a->size];
    a->high=new float[a->size];
    a->low=new float[a->size];
    a->aveT=new float[a->size];
    for (int c=JANUARY; c<=DECEMBER;c++) {
        if (c==0) cout<<"\nJanuary\n\n";
        else if (c==1) cout<<"\nFebruary\n\n";
        else if (c==2) cout<<"\nMarch\n\n";
        else if (c==3) cout<<"\nApril\n\n";
        else if (c==4) cout<<"\nMay\n\n";
        else if (c==5) cout<<"\nJune\n\n";
        else if (c==6) cout<<"\nJuly\n\n";
        else if (c==7) cout<<"\nAugust\n\n";
        else if (c==8) cout<<"\nSeptember\n\n";
        else if (c==9) cout<<"\nOctober\n\n";
        else if (c==10) cout<<"\nNovember\n\n";
        else cout<<"\nDecember\n\n";
        cout<<"Total Rainfall: ";
        cin>>a->total[c];
        cout<<"High Temperature: ";
        cin>>a->high[c];
        while(cin.fail()||(a->high[c]<(-100))||(a->high[c]>140)) {
            cout<<"\nYou must only enter a number greater than -100°F and less than 140°F!"<<endl<<endl;
            cout<<"High Temperature: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin>>a->high[c];
        }
        cout<<"Low Temperature: ";
        cin>>a->low[c];
        while(cin.fail()||(a->low[c]<(-100))||(a->low[c]>140)) {
            cout<<"\nYou must only enter a number greater than -100°F and less than 140°F!"<<endl<<endl;
            cout<<"Low Temperature: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin>>a->low[c];
        }
        a->aveT[c]=(((a->low[c])+(a->high[c]))/2);
    }
    return a;
}


float totR(WeaStat *d) {
    float tot=0;
    for (int i=JANUARY; i<=DECEMBER;i++) {
        tot+=d->total[i];
    }
    return tot;
}

float rAve(WeaStat *d) {
    float ave, tot = totR(d);    
    ave=tot/12;
    return ave;
}

void hiloest(WeaStat *d) {
    float hiest=0, lowest=d->low[0];
    int cntH, cntL;
    string hi, low;
    for (int i=JANUARY;i<=DECEMBER;i++) {
        if ((d->high[i])>hiest) {
            hiest=d->high[i];
            cntH=i;
        }
        if ((d->low[i])<lowest) {
            lowest=d->low[i]; 
            cntL=i;
        }
    }
    hi=month(cntH);
    low=month(cntL);
    cout<<"Lowest Temperature for the Year:  "<<lowest<<"°F, "<<low<<endl;
    cout<<"Highest Temperature for the Year:  "<<hiest<<"°F, "<<hi<<endl;
} 

float mAve(WeaStat *d) {
    float ave, tot = 0;   
    for (int i=JANUARY; i<=DECEMBER;i++) {
        tot+=d->aveT[i];
    }
    ave=tot/12;
    return ave;
}

string month(int n) {
    string month;
    month = (n==0)?"January":(n==1)?"February":(n==2)?"March":(n==3)?"April":
            (n==4)?"May":(n==5)?"June":(n==6)?"July":(n==7)?"August":
            (n==8)?"September":(n==9)?"October":(n==10)?"November":(n==11)?"December":"\0";
    return month;
}

void destroy(WeaStat *d) {
    delete []d->total;
    delete []d->high;
    delete []d->low;
    delete []d->aveT;
    delete d;
}
