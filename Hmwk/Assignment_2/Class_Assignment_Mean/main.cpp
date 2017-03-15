/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 7, 2017, 8:38 PM
 * Purpose: Homework Median
 * 
 *      Problem: Determine the mean average of a pointer array.
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
float meanAve(int *, int);   //Determine mean average

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int num, *array = nullptr;  char choice; bool x=true;
    
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
    
    //Output values
    cout<<endl;
    for (int c=0; c<num; c++) {
        cout<<*(array+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
    
    cout<<"\nMean Average: "<<meanAve(array, num)<<endl;
    
    delete [] array;
    array = 0;
    
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

//************************* Fill Array Function ********************************
//Description: Fill Array with random numbers
//Inputs:   No inputs but utilizes integer size and random numbers inserted
//Outputs:  output is a pointer
//******************************************************************************

int *fillAry(int n) {
    int *arrPtr = nullptr;
    arrPtr = new int[n];
    cout<<"\nGenerating "<<n<<" random numbers from 10-99..."<<endl;
    for (int c=0; c<n; c++) {
        *(arrPtr+c)=rand()%90+10;
    }
    return arrPtr;
}

//************************** Manual Fill Function ******************************
//Description: Manually Fill Array with numbers of user's choice
//Inputs:   Input integer numbers based on input size
//Outputs:  output is a pointer
//******************************************************************************

int *manFill(int n) {
    int *arrPtr = nullptr;
    arrPtr = new int[n];
    cout<<endl;
    for (int c=0; c<n; c++) {
        cout<<"Input "<<c+1<<": ";
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
    for(int c=0;c<n-1;c++){
        for(int i=c+1;i<n;i++){
            if(*(a+c)>*(a+i)){
                *(a+c)=*(a+c)^*(a+i);
                *(a+i)=*(a+c)^*(a+i);
                *(a+c)=*(a+c)^*(a+i);
            }
        }        
    }
}

//************************** Find Mean Average Function ************************
//Description: Determine the mean average of pointer array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  float - determined as mean average
//******************************************************************************

float meanAve (int *a, int n) {
    float mean=0;
    for (int i=0; i<n; i++) {
        mean+=*(a+i);
    }
    mean/=n;
    return mean;
}

