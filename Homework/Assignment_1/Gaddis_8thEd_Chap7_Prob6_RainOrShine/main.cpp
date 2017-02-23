/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 23, 2017, 11:18 AM
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
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another
const int COLS = 30;

//Function Prototypes
void count(char, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    const int ROWS = 3;
    char table[ROWS][COLS] = {};
    
    //Input Values
    ifstream in;
    in.open("RainOrShine.txt");
    
    for (int c=0; c<ROWS; c++) {
        for (int i=0; i<COLS; i++) {
            in>>table[c][i];
        }
    }
    
    in.close();
    
    for (int c=0; c<ROWS; c++) {
        for (int i=0; i<COLS; i++) {
            cout<<table[c][i]<<" ";
        }
        cout<<endl;
    }
    
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

void count(char table, int r) {
    for (int c=0; c<COLS; c++) {
        if 
    }
}