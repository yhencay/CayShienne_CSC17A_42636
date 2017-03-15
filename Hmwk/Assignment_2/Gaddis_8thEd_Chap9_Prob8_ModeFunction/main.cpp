/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 13, 2017, 8:38 PM
 * Purpose: Homework Mode
 * 
 *      Problem: In statistics, the mode of a set of values is the value that 
 *          occurs most often or with the greatest frequency. Write a function 
 *          that accepts as arguments the following:
 *              A) An array of integers
 *              B) An integer that indicates the number of elements in the 
 *                 array
 *              The function should determine the mode of the array. That is, it 
 *          should determine which value in the array occurs most often. The 
 *          mode is the value the function should return. If the array has no 
 *          mode (none of the values occur more than once), the function should 
 *          return −1. (Assume the array will always contain nonnegative 
 *          values.)
 *              Demonstrate your pointer prowess by using pointer notation 
 *          instead of array notation in this function.
 */

//System Libraries
#include <iostream> //Input Output Library
#include <cstdlib>  //C Standard Library
#include <ctime>    //Time Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
int *fillAry(int);      //Generate numbers to fill array
int *manFill(int);      //Manually fill array
void srtAry(int *, int);    //Sort array
void prtAry(int *, int);   //Display Array
int freqMod(int *, int);   //Count mode frequency
int cntMode(int *, int, int);   //Count number of modes
int *calMode (int *, int, int, int);    //Calculate Modes

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int num, nMode, freq, //number size, number of modes, frequency of modes
        *array = nullptr, *mode = nullptr;  //whole array, and the mode
    char choice;    //Manual or Auto-fill
    bool x=true;    //loop counter
    
    do {
        cout<<"Would you like to manually input elements or generate random numbers?"<<endl;
        cout<<"              M - Manual              G - Generate"<<endl<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        if (choice=='m'||choice=='M'||choice=='g'||choice=='G') x=false;
        else cout<<"\nYou can only choose 'M' or 'G'!\n"<<endl;
    } while (x);
    
    cout<<"\nNumber of Elements to Allocate: ";
    cin>>num;
    
    //Input Values
    if (choice=='m'||choice=='M') array = manFill(num);
    else array = fillAry(num);
    
    //Process by mapping inputs to outputs
    srtAry(array, num);  
    freq = freqMod(array, num);
    nMode = cntMode(array, num, freq);
    mode = calMode(array, num, freq, nMode);
    
    //Output values
    prtAry(array, num);
    
    if (nMode<1) {
        cout<<"Number of Modes: "<<nMode<<endl;
        cout<<"Frequency of Modes: 0"<<endl;
        cout<<"Modes: -1"<<endl;
    }
    else {
        cout<<"Number of Modes: "<<nMode<<endl;
        cout<<"Frequency of Modes: "<<freq<<endl;
        cout<<"Modes: ";
        for (int i=0;i<nMode;i++) {
            cout<<*(mode+i)<<" ";
        }    
        cout<<endl;
    }
    
    delete [] array;
    delete [] mode;
    array = 0;
    mode = 0;    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//************************* Fill Array Function ********************************
//Description: Fill Array with random numbers
//Inputs:   No inputs but utilizes integer size and random numbers inserted
//Outputs:  Returning a pointer
//******************************************************************************

int *fillAry(int n) {
    int *arrPtr = nullptr;  //Set pointer to zero
    arrPtr = new int[n];
    cout<<"\nGenerating "<<n<<" random numbers from 10-99..."<<endl;
    for (int c=0; c<n; c++) {
        *(arrPtr+c)=rand()%90+10;   //Generate random number
    }
    return arrPtr;
}

//************************** Manual Fill Function ******************************
//Description: Manually Fill Array with numbers of user's choice
//Inputs:   Input integer numbers based on input size
//Outputs:  output is a pointer
//******************************************************************************

int *manFill(int n) {
    int *arrPtr = nullptr;  //Set pointer to zero
    arrPtr = new int[n];
    cout<<endl;
    for (int c=0; c<n; c++) {
        cout<<"Input "<<c+1<<": ";      //Input numbers for array pointer
        cin>>*(arrPtr+c);
    }
    return arrPtr;
}

//***************************** Sort Function **********************************
//Description: Sort array ascending order
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAry(int *a, int n) {
    for(int c=0;c<n-1;c++){             //Sorting array using Mark Sort
        for(int i=c+1;i<n;i++){
            if(*(a+c)>*(a+i)){
                *(a+c)=*(a+c)^*(a+i);
                *(a+i)=*(a+c)^*(a+i);
                *(a+c)=*(a+c)^*(a+i);
            }
        }        
    }
}

//************************** Find Frequency Function ***************************
//Description: Determine the frequency of the modes
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Int - frequency number
//******************************************************************************

int freqMod(int *a, int n) {
    int c = 1, max = 0, mode = -1;       //Counter, Max and Mode
    for (int i=0; i<n-1; i++) {
        if (*(a+i)==*(a+(i+1))) {       //If the current number is the same as the next
            c++;                        //Increment
            if (c>max) {                //If counter is greater than max
                max = c;                //Set it as max
            }
        } 
        else c = 1;             //Counter reset
    }
    return max;         //Return maximum count of mode
}

//*********************** Count Number of Modes Function ***********************
//Description: Determine the frequency of the modes
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Int - frequency number
//******************************************************************************

int cntMode (int *a, int n, int f) {
    int c=1, m=0;                   //count, mode count
    for (int i=0; i<n-1; i++) {     //Loop
        if (*(a+i)==*(a+(i+1))) {   //If the current number is the same as the next
            c++;                    //Increment
            if (c==(f-1)) m++;      //If count is the same as frequency, add to mode count
        }
        else c=0;                  //Count reset 
    }
    return m;
}

//************************** Determine Mode Function ***************************
//Description: Determine the modes and put into pointer array
//Inputs:   No inputs but utilizes pointer argument and size, freq
//Outputs:  Returns pointer array of modes in the argument array
//******************************************************************************

int *calMode (int *a, int n, int f, int s) {
    int *mode=nullptr, c=1, j=0;        //pointer array, count based on number of modes, mode count
    mode=new int[s];
    for (int i=0; i<n-1; i++) {
        if (*(a+i)==*(a+(i+1))) {       //If the current number is the same as the next
            c++;                        //Increment
            if (c==(f-1)) {             //If count has the same frequency
                *(mode+j)=*(a+i);       //Add number to to mode array
                j++;                    //Increment mode array count
            }                   
        }
        else c=0;                       //count reset
    }
    return mode;
}

//*************************** Print Array  Function ****************************
//Description: Display filled array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Array
//******************************************************************************

void prtAry(int *a, int n) {
    cout<<endl;
    for (int c=0; c<n; c++) {
        cout<<*(a+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
}
