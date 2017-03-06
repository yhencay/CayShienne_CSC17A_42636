/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 5, 2017, 11:18 AM
 * Purpose: Homework Rain Or Shine
 * 
 *      Problem: An amateur meteorologist wants to keep track of weather 
 *          conditions during the past year’s three-month summer season and has 
 *          designated each day as either rainy (‘R’), cloudy (‘C’), or 
 *          sunny (‘S’). Write a program that stores this information in a 
 *          3 × 30 array of characters, where the row indicates the month 
 *          (0 = June, 1 = July, 2 = August) and the column indicates the day 
 *          of the month. Note that data are not being collected for the 31st 
 *          of any month. The program should begin by reading the weather data 
 *          in from a file. Then it should create a report that displays, for
 *          each month and for the whole three-month period, how many days were 
 *          rainy, how many were cloudy, and how many were sunny. It should 
 *          also report which of the three months had the largest number of 
 *          rainy days. Data for the program can be found in the 
 *          RainOrShine.txt file. 
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const int COLS = 30;        //2D Array Column Size

//Function Prototypes
int count(char[][COLS], char, int); //Count how many characters in char array

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS = 3;                 //Row Size
    char table[ROWS][COLS] = {};        //2D Character array
    char rain = 'R', cloud = 'C', sun = 'S';    //Character equivalent
    int juneR, juneS, juneC, julyR, julyS,
        julyC, augR, augS, augC, highest;   //Variable for results of counting
    
    //Input Values
    //Instantiate and Open Files
    ifstream in;                   
    in.open("RainOrShine.txt");
    
    for (int c=0; c<ROWS; c++) {
        for (int i=0; i<COLS; i++) {
            in>>table[c][i];
        }
    }
    
    in.close();
    
    cout<<"\t\tCHART"<<endl<<endl;
    cout<<"Day\t";
    for (int d=0;d<COLS;d++) cout<<d+1<<setw(4);        //Day Count
    cout<<endl;
    
    //Display Array
    for (int c=0; c<ROWS; c++) {
        c==0?cout<<"June\t":c==1?cout<<"July\t":cout<<"August\t";       //Display Month per count
        for (int i=0; i<COLS; i++) {
            cout<<table[c][i]<<setw(4);
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    juneR = count(table, rain, 0);
    juneS = count(table, sun, 0);
    juneC = count(table, cloud, 0);
    julyR = count(table, rain, 1);             //Call function for counting of
    julyS = count(table, sun, 1);              //rainy, sunny, cloudy per month
    julyC = count(table, cloud, 1);
    augR = count(table, rain, 2);
    augS = count(table, sun, 2);
    augC = count(table, cloud, 2);
      
    //Output values
    cout<<"\tJUNE\tJULY\tAUGUST"<<endl;
    cout<<"Rainy: \t"<<juneR<<"\t"<<julyR<<"\t"<<augR<<endl;
    cout<<"Sunny: \t"<<juneS<<"\t"<<julyS<<"\t"<<augS<<endl;
    cout<<"Cloudy:\t"<<juneC<<"\t"<<julyC<<"\t"<<augC<<endl;
    cout<<endl;
    
    //Determine which month has the most rainy days and output
    if (juneR>julyR&&juneR>augR) cout<<"LARGEST NUMBER OF RAINY DAYS: JUNE, "<<juneR<<" Days"<<endl;        
    else if (julyR>juneR&&julyR>augR) cout<<"LARGEST NUMBER OF RAINY DAYS: JULY, "<<julyR<<" Days"<<endl;
    else cout<<"LARGEST NUMBER OF RAINY DAYS: AUGUST, "<<augR<<" Days"<<endl; 
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//**************************** Count Function **********************************
//Description: Count how many times an argument occurs in the array
//Inputs:   No inputs but utilizes input file from main
//Outputs:  Returns how many the argument occurred
//******************************************************************************

int count(char table[][COLS], char w, int r) {
    int rec = 0;                    //Static Variable
    for (int c=0; c<COLS; c++) {
        if (table[r][c]==w) rec++;      //Increment if argument occurred
    }
    return rec;
}