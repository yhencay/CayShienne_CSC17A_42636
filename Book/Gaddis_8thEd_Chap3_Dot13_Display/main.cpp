/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 2:55 PM
 * Purpose: Homework 3.13
 * 
 * Problem: What will the following program display?
 * 
 *    #include <iostream>
 *    using namespace std;
 *    int main() {
 *          int integer1, integer2;
 *          double result;
 *          integer1 = 19;
 *          integer2 = 2;
 * 
 *       result = integer1 / integer2;
 *       cout << result << endl;
 *       result = static_cast<double>(integer1) / integer2;
 *       cout << result << endl;
 *       result = static_cast<double>(integer1 / integer2);
 *       cout << result << endl;
 *       return 0;
 *    }
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Declare Variables
    int num1 = 19, num2 = 2;
    float result;

    //Input Values
    //Process by mapping inputs to outputs
    //Output values
    result = num1/num2;
    cout<<result<<endl;

    result = static_cast<float>(num1)/num2;
    cout<<result<<endl;

    result = static_cast<float>(num1/num2);
    cout<<result<<endl;        
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}