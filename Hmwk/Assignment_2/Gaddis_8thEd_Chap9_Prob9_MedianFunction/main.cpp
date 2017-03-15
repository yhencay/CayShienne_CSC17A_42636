/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 7, 2017, 8:38 PM
 * Purpose: Homework Median
 * 
 *      Problem: In statistics, when a set of values is sorted in ascending or 
 *          descending order, its median is the middle value. If the set 
 *          contains an even number of values, the median is the mean, or 
 *          average, of the two middle values. Write a function that accepts as 
 *          arguments the following:
 *                  A) An array of integers
 *                  B) An integer that indicates the number of elements in 
 *                     the array
 *          The function should determine the median of the array. This value 
 *          should be returned as a double . (Assume the values in the array 
 *          are already sorted.) 
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
float median(int *, int);   //Determine median

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
    
    cout<<"\nMedian: "<<median(array, num)<<endl;
    
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

//***************************** Find Median Function ***************************
//Description: Determine the median in pointer array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  float - determined as median
//******************************************************************************

float median(int *a, int n) {
    float median; int pos=n/2, pos2=(n/2)-1;
    if (n%2==0) {
        median=*(a+pos)+*(a+pos2);
        median/=2;
        return median;
    }
    else {
        median=*(a+pos);
        return median;
    }
}

