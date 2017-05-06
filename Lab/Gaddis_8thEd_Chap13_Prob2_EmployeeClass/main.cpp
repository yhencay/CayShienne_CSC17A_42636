/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 4, 2017, 9:20 PM
 * Purpose: Homework #2 Employee Class
 * 
 * Problem: Write a class named Employee that has the following member variables:
 *      • name. A string that holds the employee’s name.
 *      • idNumber. An int variable that holds the employee’s ID number.
 *      • department. A string that holds the name of the department where 
 *          the employee works.
 *      • position. A string that holds the employee’s job title.
 *  The class should have the following constructors:
 *      • A constructor that accepts the following values as arguments and 
 *        assigns them to the appropriate member variables: employee’s name, 
 *        employee’s ID number, department, and position.
 *      • A constructor that accepts the following values as arguments and 
 *        assigns them to the appropriate member variables: employee’s name and 
 *        ID number. The department and position fields should be assigned an 
 *        empty string ( "" ).
 *      • A default constructor that assigns empty strings ( "" ) to the name , 
 *        department , and position member variables, and 0 to the idNumber 
 *        member variable. 
 *  Write appropriate mutator functions that store values in these member 
 * variables and accessor functions that return the values in these member 
 * variables. Once you have written the class, write a separate program that 
 * creates three Employee objects to hold the following data.
 *      Name        ID Number       Department          Position
 *  Susan Meyers     47899          Accounting       Vice President
 *  Mark Jones       39119              IT             Programmer
 *  Joy Rogers       81774         Manufacturing        Engineer
 *  The program should store this data in the three objects and then display 
 * the data for each employee on the screen.
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "EmpCls.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
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
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}