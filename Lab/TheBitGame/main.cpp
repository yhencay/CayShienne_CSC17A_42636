/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on April 7, 2017, 10:29 PM
  Purpose:  The Bit Game from Hacker Rank Problem
 */

//System Libraries
#include <iostream> //Input Output Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
             
//Function Prototypes
int maxXor(int, int, int);      //Determine Max Possible Value

//Executable code begins here!!!
int main(int argc, char** argv) { 
    //Declare Variables
    int num, left, right, k;
    
    //Input Values
    cout<<"Left: ";
    cin>>left;
    cout<<"Right: ";
    cin>>right;
    cout<<"K (integer): ";
    cin>>k;
    
    //Processing and mapping inputs
    num=maxXor(left, right, k);
    
    //Output Values
    cout<<"\nAnswer: "<<num<<endl;
    
    //Exit stage right!
    return 0;
}

//************************** Find Mean Average Function ************************
//Description: Find the integer denoting the maximum value of a+b satisfying 
//      criteria.
//Inputs:   No inputs but utilizes integer argument from main
//Outputs:  Integer - maximum value
//******************************************************************************

int maxXor(int left, int right, int k) {
    //Declare Variables
    int x, y, z,    //Sum holder
        h, sh, l,   //highest, second highest, lowest
        ans1, ans2, ans3,   //Values if compared to K integer
        great;      //Maximum number possible or the answer
    int a = left, a1 = a+1, b = right, b1 = b-1;
    
    x=a+b1;
    y=a+b;      //Assign values of possible sum
    z=a1+b;
    
    h=(x>y && x>z)?x:       //Determine highest number
      (y>x && y>z)?y:z;
    l=(x<y && x<z)?x:       //Determine lowest number
      (y<x && y<z)?y:z;
    if (h==x||h==y && l==x||l==y) sh=z;         //Determine second highest
    else if (h==y||h==z && l==y||l==z) sh=x;
    else sh=y;
    
    ans1=(h<=k)?h:0, ans2=(l<=k)?l:0, ans3=(sh<=k)?sh:0;        //If number is greater than K, assign 0
    
    great = (ans1>ans2 && ans1>ans3)?ans1:          //Determine greatest based on filtered answers
                (ans2>ans1 && ans2>ans3)?ans2: ans3;
    
    return great;
}