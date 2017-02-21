/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on February 20, 2017, 2:55 PM
 * Purpose: Homework 3.12
 * 
 * Problem: Complete the following program skeleton so it asks the user to enter
 *    a character. Store the character in the variable letter. Use a type cast
 *    expression with the variable in a cout statement to display the character’s
 *    ASCII code on the screen.
 * 
 *      #include <iostream>
 *      using namespace std;
 *      int main() {
 *          char letter;
 *          // Finish this program
 *          // as specified above.
 *          return 0;
 *      }
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
    char letter;
    
    //Input Values
    cout<<"Enter a character: ";
    cin>>letter;
    
    //Process by mapping inputs to outputs
    //Output values
    cout<<"\nThe ASCII Code of "<<letter<<" is "<<static_cast<int>(letter)<<endl;
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}