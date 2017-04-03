/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on March 29, 2017, 4:14 PM
  Purpose:  Homework 3 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string>   //String Library
#include <iomanip>
using namespace std;

//User Libraries
#include "Headers.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
             SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };
             
//Function Prototypes
void hProb1();
void filData(MovData &);
void shwData(MovData);
void hProb2();
void dataFil(MovProf &);
void dataShw(MovProf, float);
void hProb3();
void filSls(SlsData &);     //Fill Sales Data
void slsDis(SlsData);       //Sales Display
void hProb4();
WeaStat *wdrFill(int);
void fillWdr(WeaStat &);
void destroy(WeaStat *);
float totR(WeaStat *);
float rAve(WeaStat *);
float mAve(WeaStat *);
void hiloest(WeaStat *);
string month(int);
void hProb5();
WeStat *wdrFil(int);
void filWdr(WeStat &);
void destry(WeStat *);
float tot(WeStat *);
float rAve5(WeStat *, float);
float mAve5(WeStat *);
void hilest(WeStat *);
string month2(int);
void hProb6();
SoccerS *plyFill(int);
void destroy(SoccerS *);
short totPnts(SoccerS *, int);
void hiest(SoccerS *, int);
void dsPlyrs(SoccerS *, int);

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"------------------------------------------------"<<endl;
        cout<<"              CHOOSE FROM THE LIST              "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Type A : Problem 1 - MOVIE DATA"<<endl;
        cout<<"Type B : Problem 2 - MOVIE PROFIT"<<endl;
        cout<<"Type C : Problem 3 - CORPORATE SALES DATA"<<endl;
        cout<<"Type D : Problem 4 - WEATHER STATISTICS"<<endl;
        cout<<"Type E : Problem 5 - WEATHER STATISTICS MODIFIED"<<endl;
        cout<<"Type F : Problem 6 - SOCCER SCORES"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;

        //Switch to determine the Problem
        switch(choice){
            case 'f':
            case 'F': {hProb6();break;}
            case 'e': 
            case 'E': {hProb5();break;}
            case 'd':
            case 'D': {hProb4();break;}
            case 'c':
            case 'C': {hProb3();break;}
            case 'b': 
            case 'B': {hProb2();break;}
            case 'a':
            case 'A': {hProb1();break;}
            
            default: {
                cout<<"You are exiting the program!"<<endl;
                x=false;
            } 
        }
    } while(x);
    
    //Exit stage right!
    return 0;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 1 ***********************************
// Problem: Write a program that uses a structure named MovieData to store the 
//      following information about a movie:
//               Title
//               Director
//               Year Released
//               Running Time (in minutes)
//      The program should create two MovieData variables, store values in their 
//      members, and pass each one, in turn, to a function that displays the 
//      information about the movie in a clearly formatted manner. 
//Inputs:  Struct variable
//Outputs:   Data input
//******************************************************************************

void hProb1(){
    cout<<"Homework - MOVIE DATA"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');
    MovData data;
    //Fill Data
    filData(data);
    //Display Data
    shwData(data);
    cout<<endl;
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
// Problem: Modify the Movie Data program written for Programming Challenge 1 to 
//      include two additional members that hold the movie’s production costs 
//      and first-year revenues. Modify the function that displays the movie 
//      data to display the title, director, release year, running time, and 
//      first year’s profit or loss.
//Inputs:  Struct variable
//Outputs:   Data input
//******************************************************************************

void hProb2(){
    cout<<"Homework - MOVIE PROFIT"<<endl<<endl; 
    //Declare Variables
    MovProf data;
    float winLos, equal=0;
    cin.ignore(256, '\n');
    dataFil(data);
    
    //Process
    winLos = (data.profit>data.cost)?data.profit-data.cost:
             (data.profit<data.cost)?data.cost-data.profit:equal;
    
    //Output
    dataShw(data, winLos);
       
    cout<<endl;
}

void dataFil(MovProf &data) {
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

void dataShw(MovProf data, float winLos) {
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
// Problem: Write a program that uses a structure to store the following data 
//     on a company division:
//             Division Name (such as East, West, North, or South)
//             First-Quarter Sales
//             Second-Quarter Sales
//             Third-Quarter Sales
//             Fourth-Quarter Sales
//             Total Annual Sales
//             Average Quarterly Sales
//     The program should use four variables of this structure. Each variable 
//  should represent one of the following corporate divisions: East, West, 
//  North, and South. The user should be asked for the four quarters’ sales 
//  figures for each division. Each division’s total and average sales should be 
//  calculated and stored in the appropriate member of each structure variable. 
//  These figures should then be displayed on the screen.
//          Input Validation: Do not accept negative numbers for any sales 
//                      figures.
//Inputs:  float - sales
//Outputs:  average sales
//******************************************************************************

void hProb3(){
    cout<<"Homework - CORPORATE SALES DATA"<<endl<<endl;
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
    
    cout<<endl;
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
// Problem: Write a program that uses a structure to store the following weather 
//     data for a particular month:
//             Total Rainfall
//             High Temperature
//             Low Temperature
//             Average Temperature
//         The program should have an array of 12 structures to hold weather 
//      data for an entire year. When the program runs, it should ask the user 
//      to enter data for each month. (The average temperature should be 
//      calculated.) Once the data are entered for all the months, the program 
//      should calculate and display the average monthly rainfall, the total 
//      rainfall for the year, the highest and lowest temperatures for the
//      year (and the months they occurred in), and the average of all the 
//      monthly average temperatures.
//             Input Validation: Only accept temperatures within the range 
//                      between –100 and +140 degrees Fahrenheit.
//Inputs:  float
//Outputs:  Results
//******************************************************************************

void hProb4() {
    cout<<"Homework - WEATHER STATISTICS"<<endl<<endl;
    //Declare Variables
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
    cout<<endl;
}

WeaStat *wdrFill(int s) {
    WeaStat *a = new WeaStat;
    a->size=s;
    a->total=new float[a->size];
    a->high=new float[a->size];
    a->low=new float[a->size];
    a->aveT=new float[a->size];
    for (int c=0; c<a->size;c++) {
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
    for (int i=0; i<d->size;i++) {
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
    for (int i=0;i<d->size;i++) {
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
    for (int i=0; i<d->size;i++) {
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
// Problem: Modify the program that you wrote for Programming Challenge 4 so it
//       defines an enumerated data type with enumerators for the months 
//       ( JANUARY , FEBRUARY , etc.). The program should use the enumerated 
//       type to step through the elements of the array.
//Inputs:  float
//Outputs:  Results
//******************************************************************************

void hProb5(){
    cout<<"Homework - WEATHER STATISTICS MODIFICATION"<<endl<<endl;
    //Declare Variables
    int size=12;    
    WeStat *data=wdrFil(size);
    
    float yearRn=tot(data);
    float mAveRn=rAve5(data, yearRn);
    float mTemAve=mAve5(data);
    
    //Output the created array
    cout<<endl;
    cout<<"Average Monthly Rainfall:  "<<mAveRn<<" inches"<<endl;
    cout<<"Total Rainfall of the Year:  "<<yearRn<<" inches"<<endl;
    hilest(data);
    cout<<"Average of All Average Monthly Temperature:  "<<mTemAve<<" °F"<<endl;
    
    destry(data);
    
    cout<<endl;
}

WeStat *wdrFil(int s) {
    WeStat *a = new WeStat;
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

float tot(WeStat *d) {
    float tot=0;
    for (int i=JANUARY; i<=DECEMBER;i++) {
        tot+=d->total[i];
    }
    return tot;
}

float rAve5(WeStat *d, float tot) {
    float ave; 
    ave=tot/12;
    return ave;
}

void hilest(WeStat *d) {
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

float mAve5(WeStat *d) {
    float ave, tot = 0;   
    for (int i=JANUARY; i<=DECEMBER;i++) {
        tot+=d->aveT[i];
    }
    ave=tot/12;
    return ave;
}

string month2(int n) {
    string month;
    month = (n==0)?"January":(n==1)?"February":(n==2)?"March":(n==3)?"April":
            (n==4)?"May":(n==5)?"June":(n==6)?"July":(n==7)?"August":
            (n==8)?"September":(n==9)?"October":(n==10)?"November":(n==11)?"December":"\0";
    return month;
}

void destry(WeStat *d) {
    delete []d->total;
    delete []d->high;
    delete []d->low;
    delete []d->aveT;
    delete d;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
// Problem: Write a program that stores the following data about a soccer player
//       in a structure:
//              Player’s Name
//              Player’s Number
//              Points Scored by Player
//      The program should keep an array of 12 of these structures. Each element 
//    is for a different player on a team. When the program runs it should ask 
//    the user to enter the data for each player. It should then show a table 
//    that lists each player’s number, name, and points scored. The program 
//    should also calculate and display the total points earned by the team. The 
//    number and name of the player who has earned the most points should also 
//    be displayed.
//          Input Validation: Do not accept negative values for players’ numbers 
//                  or points scored.
//Inputs:  string, int and float
//Outputs:  results
//******************************************************************************

void hProb6(){
    cout<<"Homework - SOCCER SCORES"<<endl<<endl;
    //Declare Variables
    int size=12;    
    cin.ignore(256, '\n');
    SoccerS *plyrs=plyFill(size);
    short total=totPnts(plyrs, size);
    
    //Output the created array
    dsPlyrs(plyrs, size);
    
    destroy(plyrs);
    
    cout<<endl;
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
        while(cin.fail()||(a->points[c]<0)){
            cout<<"\nNo negative values allowed!"<<endl<<endl;
            cout<<"Points Scored by Player: ";
            cin.clear();
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