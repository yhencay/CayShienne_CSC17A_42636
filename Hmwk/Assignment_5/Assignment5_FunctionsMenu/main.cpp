/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on May 10, 2017, 4:14 PM
  Purpose:  Homework 5 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string>   //String Library
using namespace std;

//User Libraries
#include "AllCls.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
             
//Function Prototypes
void hProb1();
void hProb2();
void hProb3();
void hProb4();
void hProb5();
void hProb6();
void hProb7();
void hProb8();

//Executable code begins here!!!
int main(int argc, char** argv) {    
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"                  CHOOSE FROM THE LIST               "<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"Type A : CH. 13 Problem 1  - DATE CLASS"<<endl;
        cout<<"Type B : CH. 13 Problem 2  - EMPLOYEE CLASS"<<endl;
        cout<<"Type C : CH. 13 Problem 3  - CAR CLASS"<<endl;
        cout<<"Type D : CH. 13 Problem 4  - PERSONAL INFO"<<endl;
        cout<<"Type E : CH. 13 Problem 10 - NUMBER ARRAY"<<endl;
        cout<<"Type F : CH. 14 Problem 1  - NUMBERS CLASS"<<endl;
        cout<<"Type G : CH. 14 Problem 2  - DAY OF THE YEAR"<<endl;
        cout<<"Type H : CH. 14 Problem 3  - DAY OF THE YEAR MOD"<<endl;
        cout<<"Type I : MISSING"<<endl;
        cout<<"Type J : MISSING"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;

        //Switch to determine the Problem
        switch(choice){
            case 'h':
            case 'H': {hProb8();break;}
            case 'g':
            case 'G': {hProb7();break;}
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
// Problem: Design a class called Date. The class should store a date in three 
//      integers: month, day , and year. There should be member functions to 
//      print the date in the following forms:
//               12/25/2014
//               December 25, 2014
//               25 December 2014
//    Demonstrate the class by writing a complete program implementing it.
//  Input Validation: Do not accept values for the day greater than 31 or less 
//     than 1. Do not accept values for the month greater than 12 or less than 1.
//Inputs:  Int
//Outputs:   Date Forms
//******************************************************************************

void hProb1(){
    cout<<"Homework - DATE CLASS"<<endl<<endl;
    //Declare Variables
    int m, d, y;
    
    //Input Values
    cout<<"Input Month: ";
    cin>>m;
    while(cin.fail()||(m<1)||(m>12)) {
        cout<<"\nInvalid Input. Try again!"<<endl<<endl;
        cout<<"Input Month: ";
        cin.clear();
        cin>>m;
    }
    
    cout<<"Input Day: ";
    cin>>d;
    while(cin.fail()||(d<1)||(d>31)) {
        cout<<"\nInvalid Input. Try again!"<<endl<<endl;
        cout<<"Input Day: ";
        cin.clear();
        cin>>d;
    }
    
    cout<<"Input Year: ";
    cin>>y;
    
    //Process by mapping inputs to outputs
    Date prnDate(m, d, y);
    
    //Output values
    prnDate.prntD8();
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
// Problem: Write a class named Employee that has the following member variables:
//      • name. A string that holds the employee’s name.
//      • idNumber. An int variable that holds the employee’s ID number.
//      • department. A string that holds the name of the department where 
//          the employee works.
//      • position. A string that holds the employee’s job title.
//  The class should have the following constructors:
//      • A constructor that accepts the following values as arguments and 
//        assigns them to the appropriate member variables: employee’s name, 
//        employee’s ID number, department, and position.
//      • A constructor that accepts the following values as arguments and 
//        assigns them to the appropriate member variables: employee’s name and 
//        ID number. The department and position fields should be assigned an 
//        empty string ( "" ).
//      • A default constructor that assigns empty strings ( "" ) to the name , 
//        department , and position member variables, and 0 to the idNumber 
//        member variable. 
//  Write appropriate mutator functions that store values in these member 
// variables and accessor functions that return the values in these member 
// variables. Once you have written the class, write a separate program that 
// creates three Employee objects to hold the following data.
//      Name        ID Number       Department          Position
//  Susan Meyers     47899          Accounting       Vice President
//  Mark Jones       39119              IT             Programmer
//  Joy Rogers       81774         Manufacturing        Engineer
//  The program should store this data in the three objects and then display 
// the data for each employee on the screen.
//Inputs:  Embedded Input
//Outputs:   Constructor Output
//******************************************************************************

void hProb2(){
    cout<<"Homework - EMPLOYEE CLASS"<<endl<<endl; 
    //Declare Variables
    string emp1="Susan Meyers", emp2="Mark Jones", emp3="Joy Rogers", 
           dep1="Accounting", dep2="IT", dep3="Manufacturing", 
           pos1="Vice President", pos2="Programmer", pos3="Engineer";
    int id1=47899, id2=39119, id3=81774;
    Staff empNum1(emp1, id1, dep1, pos1);
    Staff empNum2(emp2, id2);
    Staff empNum3;
    
    //Input Values
    empNum2.setDept(dep2);
    empNum2.setPos(pos2);
    empNum3.setName(emp3);
    empNum3.setID(id3);
    empNum3.setDept(dep3);
    empNum3.setPos(pos3);
    
    //Output values
    cout<<"\n ----------------------------------------------------------------------"<<endl;
    cout<<"|     Name          ID Number       Department        Position         |"<<endl;
    cout<<"|----------------------------------------------------------------------|"<<endl;
    cout<<"| "<<empNum1.getName()<<"\t    "<<empNum1.getID()<<"\t    "<<empNum1.getDept()<<"\t      "<<empNum1.getPos()<<"   |"<<endl;
    cout<<"| "<<empNum2.getName()<<"\t    "<<empNum2.getID()<<"\t    "<<empNum2.getDept()<<"\t\t      "<<empNum2.getPos()<<"       |"<<endl; 
    cout<<"| "<<empNum3.getName()<<"\t    "<<empNum3.getID()<<"\t    "<<empNum3.getDept()<<"     "<<empNum3.getPos()<<"\t       |"<<endl;
    cout<<" ----------------------------------------------------------------------"<<endl<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
// Problem: Write a class named Car that has the following member variables:
//              • yearModel . An int that holds the car’s year model.
//              • make . A string that holds the make of the car.
//              • speed . An int that holds the car’s current speed.
//  In addition, the class should have the following constructor and other 
//  member functions.
//      • Constructor. The constructor should accept the car’s year model and 
//        make as arguments. These values should be assigned to the object’s 
//        yearModel and make member variables. The constructor should also 
//        assign 0 to the speed member variables.
//      • Accessor. Appropriate accessor functions to get the values stored in 
//        an object’s yearModel , make , and speed member variables.
//      • accelerate . The accelerate function should add 5 to the speed member 
//        variable each time it is called.
//      • brake . The brake function should subtract 5 from the speed member 
//        variable each time it is called.
//  Demonstrate the class in a program that creates a Car object, and then calls 
//  the accelerate function five times. After each call to the accelerate 
//  function, get the current speed of the car and display it. Then, call the 
//  brake function five times. After each call to the brake function, get the 
//  current speed of the car and display it.
//Inputs:  String, Int
//Outputs:  Car Info
//******************************************************************************

void hProb3(){
    cout<<"Homework - CAR CLASS"<<endl<<endl;
    cin.ignore(256, '\n');
    //Declare Variables
    int yr;
    string m;
    
    //Input Values
    cout<<"Car Make: ";
    getline(cin, m);
    cout<<"Year Model: ";
    cin>>yr;  
    
    //Process by mapping inputs to outputs
    Car data(yr, m);
    
    //Output values
    cout<<endl<<endl<<"Information"<<endl<<endl;
    cout<<"Car: "<<data.getMake()<<endl;
    cout<<"Year Model: "<<data.getYr()<<endl;
    cout<<"Speed: "<<data.getSpd()<<" mph"<<endl<<endl;
    cout<<"Press ENTER to start accelerating!"<<endl;
    cin.ignore(256, '\n');
    cin.get();
    
    for (int i=0; i<5; i++) {
        data.axlr8();
        cout<<"Current Speed: "<<data.getSpd()<<" mph"<<endl;
    }
    
    cout<<"\nPress ENTER to start braking!"<<endl;
    cin.get();
    
    for (int i=0; i<5; i++) {
        data.brake();
        cout<<"Current Speed: "<<data.getSpd()<<" mph"<<endl;
    }
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
// Problem: Design a class that holds the following personal data: name, address, 
//      age, and phone number. Write appropriate accessor and mutator functions. 
//      Demonstrate the class by writing a program that creates three instances 
//      of it. One instance should hold your information, and the other two 
//      should hold your friends’ or family members’ information.
//Inputs:  Int, String
//Outputs:  Personal Info
//******************************************************************************

void hProb4() {
    cout<<"Homework - PERSONAL INFO"<<endl<<endl;
    //Declare Variables
    int entry, ch;
    bool x=true;
    
    //Input Values
    cout<<"How many entries do you want to input (including yourself)? ";
    cin>>entry;
    cin.ignore(256, '\n');
    PerInfo *data=new PerInfo[entry];
    
    //Process by mapping inputs to outputs
    for (int i=0; i<entry; i++) {
        cout<<"\nEntry #"<<i+1<<endl;
        data[i].setInfo();
    }
    
    //Output values
    do {
        cout<<"\nWhich entry would you like to view?"<<endl;
        cout<<"0 | QUIT"<<endl;
        for (int i=0; i<entry; i++) {
            cout<<i+1<<" | "<<data[i].getName()<<endl;
        }
        cout<<"\nCHOICE: ";
        cin>>ch;
        if (ch==0) x=false;
        else {
            ch-=1;
            if (ch<0||ch>=entry) cout<<"\nEntry does not exist!\n\n";
            else data[ch].disInfo();
        }
    } while(x);
        
    //Delete Pointer Array
    delete []data;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
// Problem: Design a class that has an array of floating-point numbers. The 
//      constructor should accept an integer argument and dynamically allocate 
//      the array to hold that many numbers. The destructor should free the 
//      memory held by the array. In addition, there should be member functions 
//      to perform the following operations:
//              • Store a number in any element of the array
//              • Retrieve a number from any element of the array
//              • Return the highest value stored in the array
//              • Return the lowest value stored in the array
//              • Return the average of all the numbers stored in the array
//      Demonstrate the class in a program.
//Inputs:  Float
//Outputs:  Specific values like highest, lowest and average
//******************************************************************************

void hProb5(){
    cout<<"Homework - NUMBER ARRAY"<<endl<<endl;
    //Declare Variables
    int sizeAry, access;
    bool z=true;
    
    //Input Values
    cout<<"How many elements do you want to input? ";
    cin>>sizeAry;
    
    //Process by mapping inputs to outputs
    NumAry numbers(sizeAry);
    
    //Output values
    do {
        cout<<"\nInput number of element in the array you want to access.\n\n";
        cout<<"Input Number: ";
        cin>>access;
        if (access<1||access>sizeAry) cout<<"\nElement does not exist!\n\n";
        else {
            access-=1;
            cout<<"\nThe element is: "<<numbers.getNum(access);
            z=false;
        }
    } while(z);
    
    cout<<"\nHighest Value: "<<numbers.highest()<<endl;
    cout<<"Lowest Value: "<<numbers.lowest()<<endl;
    cout<<"Average: "<<numbers.average()<<endl;
   
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
// Problem: Design a class Numbers that can be used to translate whole dollar 
//      amounts in the range 0 through 9999 into an English description of the 
//      number. For example, the number 713 would be translated into the string 
//      seven hundred thirteen , and 8203 would be translated into eight 
//      thousand two hundred three . The class should have a single integer
//      member variable:
//              int number;
//      and a static array of string objects that specify how to translate key 
//      dollar amounts into the desired format. For example, you might use 
//      static strings such as
//          string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
//          string hundred = "hundred";
//          string thousand = "thousand";
//  The class should have a constructor that accepts a nonnegative integer and 
//  uses it to initialize the Numbers object. It should have a member function 
//  print() that prints the English description of the Numbers object. 
//  Demonstrate the class by writing a main program that asks the user to enter 
//  a number in the proper range and then prints out its English description.
//Inputs:  Integer
//Outputs:  English Description
//******************************************************************************

void hProb6(){
    cout<<"Homework - NUMBERS CLASS"<<endl<<endl;
    //Declare Variables
    int input;
    
    //Input Values
    do {
        cout<<"Enter number from 0-9999."<<endl<<endl;
        cout<<"INPUT: ";
        cin>>input;
        if (input<0||input>9999) cout<<"\nInput Invalid!\n\n";
    } while(input<0||input>9999);
    
    
    //Process by mapping inputs to outputs
    Numbers trans(input);
    
    //Output values
    cout<<endl;
    trans.prntWrd();
    cout<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 7 ***********************************
// Problem: Design a class Numbers that can be used to translate whole dollar 
//      amounts in the range 0 through 9999 into an English description of the 
//      number. For example, the number 713 would be translated into the string 
//      seven hundred thirteen , and 8203 would be translated into eight 
//      thousand two hundred three . The class should have a single integer
//      member variable:
//              int number;
//      and a static array of string objects that specify how to translate key 
//      dollar amounts into the desired format. For example, you might use 
//      static strings such as
//          string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
//          string hundred = "hundred";
//          string thousand = "thousand";
//  The class should have a constructor that accepts a nonnegative integer and 
//  uses it to initialize the Numbers object. It should have a member function 
//  print() that prints the English description of the Numbers object. 
//  Demonstrate the class by writing a main program that asks the user to enter 
//  a number in the proper range and then prints out its English description.
//Inputs:  Read from file
//Outputs:  First 24 lines of file if it's more than 24 lines
//******************************************************************************

void hProb7(){
    cout<<"Homework - DAY OF THE YEAR"<<endl<<endl;
    //Declare Variables
    int userIn;
    
    //Input Values
    do {
        cout<<"Enter Day: ";
        cin>>userIn;
        if (userIn<=0||userIn>365) cout<<"\nInvalid Input!\n\n";
    } while(userIn<=0||userIn>365);
    
    //Process by mapping inputs to outputs
    DayOfYr monDate(userIn);
    
    //Output values
    monDate.prntDay();
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 8 ***********************************
// Problem: Modify the DayOfYear class, written in Programming Challenge 2, to 
//    add a constructor that takes two parameters: a string object representing 
//    a month and an integer in the range 0 through 31 representing the day of 
//    the month. The constructor should then initialize the integer member of 
//    the class to represent the day specified by the month and day of month 
//    parameters. The constructor should terminate the program with an 
//    appropriate error message if the number entered for a day is outside the 
//    range of days for the month given.
//Inputs:  String and Int
//Outputs:  Specific DAY of year
//******************************************************************************

void hProb8(){
    cout<<"Homework - DAY OF THE YEAR MODIFICATION"<<endl<<endl;
    //Declare Variables
    int date;
    string mon;
    
    //Input Values
    cout<<"Month should start with a capital letter when you type, otherwise, it won't be accepted."<<endl<<endl;
    cout<<"Enter Month: ";
    cin>>mon;
    cout<<"Enter Day: ";
    cin>>date;
    
    //Process by mapping inputs to outputs
    YrMonth dayNow(mon, date);
    
    cout<<endl;
}
