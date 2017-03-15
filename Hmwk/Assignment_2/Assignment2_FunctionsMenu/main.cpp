/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on March 14, 2017, 4:14 PM
  Purpose:  Homework 2 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string> //String Library
#include <cstdlib> //Standard Library
#include <ctime>    //Time Library
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another

//Function Prototypes
void hProb1();
int *alloc8(int);   //Function to allocate memory
void hProb2();
void sortAry(float *, int);     //Sort array function
float calcAve(float *, int);    //Calculate average function
void showAry(float *, int);     //Display Array
void hProb3();
float calAve(float *, int);    //Calculate average function w/o lowest
void shwAry(float *, int);     //Display Array w/0 lowest
void hProb4();
void srtAryS(float *, string *, int);  //Sort array function with string name equivalent
void shwAry(float *, string *, int);   //Display array
void hProb5();
float *donFill(int);          //Donation fill array
void srtAryA(float *, int);   //Sort array ascending order
void prntAry(float *, int);   //Display array
void hProb6();
void srtAryD(float *, int);    //Sort array descending order
void hProb7();
int *fillAry(int);      //Generate numbers to fill array
int *manFill(int);      //Manually fill array
void srtAry(int *, int);    //Sort array
void prtAry(int *, int);   //Display Array
int freqMod(int *, int);   //Count mode frequency
int cntMode(int *, int, int);   //Count number of modes
int *calMode (int *, int, int, int);    //Calculate Modes
void hProb8();
float median(int *, int);   //Determine median
void hProb9();
int *copyRev(int *, int);   //Reversed copy of array
void pntAry(int *, int);   //Print Array
void hProb10();
float meanAve(int *, int);   //Determine mean average

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"------------------------------------------------"<<endl;
        cout<<"              CHOOSE FROM THE LIST              "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Type A : Problem 1 - ARRAY ALLOCATOR"<<endl;
        cout<<"Type B : Problem 2 - TEST SCORES #1"<<endl;
        cout<<"Type C : Problem 3 - DROP LOWEST SCORE"<<endl;
        cout<<"Type D : Problem 4 - TEST SCORES #2"<<endl;
        cout<<"Type E : Problem 6 - CASE STUDY MODIFICATION #1"<<endl;
        cout<<"Type F : Problem 7 - CASE STUDY MODIFICATION #2"<<endl;
        cout<<"Type G : Problem 8 - MODE FUNCTION"<<endl;
        cout<<"Type H : Problem 9 - MEDIAN FUNCTION"<<endl;
        cout<<"Type I : Problem 10 - REVERSE ARRAY"<<endl;
        cout<<"Type J : CLASS Assignment - MEAN"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;

        //Switch to determine the Problem
        switch(choice){
            case 'j':
            case 'J': {hProb10();break;}
            case 'i':
            case 'I': {hProb9();break;}
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
//Problem: Write a function that dynamically allocates an array of 
//    integers. The function should accept an integer argument indicating 
//    the number of elements to allocate. The function should return a 
//    pointer to the array.
//Inputs:  Random numbers
//Outputs:   Generate numbers in pointer array
//******************************************************************************

void hProb1(){
    cout<<"Homework - ARRAY ALLOCATOR"<<endl<<endl;
    //Declare Variables
    int num, *array = nullptr;
    
    cout<<"Number of Elements to Allocate: ";
    cin>>num;
    cout<<"\nGenerating "<<num<<" random numbers from 10-99..."<<endl<<endl;
    
    //Input Values
    //Process by mapping inputs to outputs
    array = alloc8(num);
    
    //Output values
    for (int c=0; c<num; c++) {
        cout<<*(array+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
    
    delete [] array;
    array = 0;
    
    cout<<endl;
}

//******************** Dynamic Memory Allocation Function **********************
//Description: Allocate array of integers
//Inputs:   No inputs but utilizes integer argument
//Outputs:  Returns pointer to array
//******************************************************************************

int *alloc8(int n) {
    int *arrPtr = nullptr;
    arrPtr = new int[n];
    for (int c=0; c<n; c++) {
        *(arrPtr+c)=rand()%90+10;     //Insert random number to array pointer
    }
    return arrPtr;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
//Description: Write a program that dynamically allocates an array large 
//          enough to hold a user defined number of test scores. Once all the 
//          scores are entered, the array should be passed to a function that 
//          sorts them in ascending order. Another function should be called 
//          that calculates the average score. The program should display the 
//          sorted list of scores and averages with appropriate headings. Use 
//          pointer notation rather than array notation whenever possible.
//          Input Validation: Do not accept negative numbers for test scores.
//Inputs:  float - grades
//Outputs:  sorted array and average of grades
//******************************************************************************

void hProb2(){
    cout<<"Homework - TEST SCORES #1"<<endl<<endl;     
    //Declare Variables
    int numTest;
    float average;
    
    //Input Values
    cout<<"Enter number of test scores: ";
    cin>>numTest;
    cout<<endl;
    
    float *tests = nullptr;
    tests = new float[numTest];
    
    for (int c=0; c<numTest; c++) {
        do {
            cout<<"Test "<<c+1<<": ";       //Input test scores
            cin>>*(tests+c);
            if (*(tests+c)<0) cout<<"\nInvalid Input!"<<endl<<endl;
        } while (*(tests+c)<0);               //Invalidate if less than 0
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    sortAry(tests, numTest);
    average = calcAve(tests, numTest);
    
    //Output values
    showAry(tests, numTest);
    cout<<"\nAverage: "<<average<<endl;
    
    delete [] tests;
    tests = 0;
       
    cout<<endl;
}

//***************************** Sort Function **********************************
//Description: Sort array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void sortAry(float *t, int s) {
    float temp;
    for (int i=0; i<s-1; i++) {
        for (int c=i+1; c<s; c++) {
            if (*(t+i)>*(t+c)) {
                temp = *(t+i);
                *(t+i) = *(t+c);
                *(t+c) = temp;
            }
        }
    }
}

//*********************** Calculate Average Function ***************************
//Description: Count how many times an argument occurs in the array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Returns float average
//******************************************************************************

float calcAve(float *t, int s) {
    float ave = 0;
    for (int c=0; c<s; c++) {
        ave+=*(t+c);
    }
    ave/=s;
    return ave;
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array
//******************************************************************************

void showAry(float *t, int s) {
    for (int c=0; c<s; c++) {
        cout<<*(t+c)<<endl;
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
//Description: Modify Problem 2 above so the lowest test score is dropped. 
//    This score should not be included in the calculation of the average.
//Inputs:  float - grades
//Outputs:  average of grades with the lowest dropped
//******************************************************************************

void hProb3(){
    cout<<"Homework - DROP LOWEST"<<endl<<endl;
    //Declare Variables
    int numTest;
    float average;
    
    //Input Values
    cout<<"Enter number of test scores: ";
    cin>>numTest;
    cout<<endl;
    
    float *tests = nullptr;
    tests = new float[numTest];
    
    for (int c=0; c<numTest; c++) {
        do {
            cout<<"Test "<<c+1<<": ";       //Input test scores
            cin>>*(tests+c);
            if (*(tests+c)<0) cout<<"\nInvalid Input!"<<endl<<endl;
        } while (*(tests+c)<0);               //Invalidate if less than 0
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    sortAry(tests, numTest);
    cout<<*(tests+0)<<" - Lowest Score is dropped!"<<endl<<endl;
    
    average = calAve(tests, numTest);
    
    //Output values
    shwAry(tests, numTest);
    cout<<"\nAverage: "<<average<<endl;
    
    delete [] tests;
    tests = 0;
    
    cout<<endl;
}

//*********************** Calculate Average Function ***************************
//Description: Count average dropping lowest score
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Returns float average
//******************************************************************************

float calAve(float *t, int s) {
    float ave = 0;
    for (int c=1; c<s; c++) {
        ave+=*(t+c);
    }
    ave/=(s-1);
    return ave;
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array
//******************************************************************************

void shwAry(float *t, int s) {
    for (int c=1; c<s; c++) {
        cout<<*(t+c)<<endl;
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
//Description: Modify the program of Programming Challenge 2 to allow the user
//    to enter name-score pairs. For each student taking a test, the user 
//    types the student’s name followed by the student’s integer test 
//    score. Modify the sorting function so it takes an array holding the
//    student names and an array holding the student test scores. When 
//    the sorted list of scores is displayed, each student’s name should 
//    be displayed along with his or her score. In stepping through the 
//    arrays, use pointers rather than array subscripts. 
//Inputs:  String and float - student name and grade
//Outputs:  Sorted array by grade with appropriate name
//******************************************************************************

void hProb4() {
    cout<<"Homework - TEST SCORES #2"<<endl<<endl;
    //Declare Variables
    int numTest;
    float average;
    string dummy;       //Dummy string for getline
    
    //Input Values
    cout<<"Enter number of students: ";
    cin>>numTest;
    cout<<endl;
    getline(cin, dummy);
    
    float *tests = nullptr;
    string *student = nullptr;
    
    tests = new float[numTest];
    student = new string[numTest];
    
    for (int c=0; c<numTest; c++) {
        cout<<"Student Name: ";
        getline(cin, student[c]);
        do {
            cout<<"Test Score: ";
            cin>>tests[c];
            getline(cin, dummy);
            if (tests[c]<0) cout<<"\nInvalid Input!"<<endl<<endl;
        } while (tests[c]<0);   //Invalidate if score is less than 0
        cout<<endl;
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    srtAryS(tests, student, numTest);
    
    //Output values
    shwAry(tests, student, numTest);
    
    delete [] tests;
    delete [] student;
    
    cout<<endl;
}

//**************************** Sort Array Function *****************************
//Description: Sorts array with name equivalent to score
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAryS(float *t, string *stud, int s) {
    float temp; string temp2;
    for (int i=0; i<s-1; i++) {
        for (int c=i+1; c<s; c++) {
            if (t[i]>t[c]) {
                temp = t[i];
                t[i] = t[c];
                t[c] = temp;
                temp2 = stud[i];
                stud[i] = stud[c];
                stud[c] = temp2;
            }
        }
    }
}

//**************************** Show Array Function *****************************
//Description: Display Array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Outputs Array with names equivalent with score
//******************************************************************************

void shwAry(float *t, string *stud, int s) {
    for (int c=0; c<s; c++) {
        cout<<*(stud+c)<<"\t"<<*(t+c)<<endl;
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
//Description: Modify Program 9-19 (the United Cause case study program) so it 
//      can be used with any set of donations. The program should dynamically 
//      allocate the donations array and ask the user to input its values.
//Inputs:  Float values from user input
//Outputs:  Sorted list of donations in ascending order
//******************************************************************************

void hProb5(){
    cout<<"Homework - CASE STUDY MODIFICATION #1 (ASCENDING ORDER)"<<endl<<endl;
    //Declare Variables
    float *donate = nullptr;  
    int size;
    char choice; 
    bool x=true;
    
    cout<<"Number of set donations: ";
    cin>>size;
    
    //Input Values
    donate = donFill(size);
    
    //Process by mapping inputs to outputs
    srtAryA(donate, size);
    
    //Output values
    cout<<endl<<"The donations sorted in ascending order: "<<endl;
    prntAry(donate, size);
    
    delete [] donate;
    donate = 0;
    
    cout<<endl;
}

//************************ Donation Fill Function ******************************
//Description: Manually Fill Array with donation's of user's input
//Inputs:   Input integer numbers based on input size
//Outputs:  Returns a pointer
//******************************************************************************

float *donFill(int s) {
    float *d = nullptr;       //Donated
    d = new float[s];
    cout<<endl;
    for (int c=0; c<s; c++) {
        cout<<"Amount "<<c+1<<": $ ";
        cin>>*(d+c);
    }
    return d;
}

//***************************** Sort Function **********************************
//Description: Sort array ascending order
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAryA(float *a, int n) {
    float temp;
    for(int c=0;c<n-1;c++){
        for(int i=c+1;i<n;i++){
            if(*(a+c)>*(a+i)){
                temp = *(a+c);
                *(a+c) = *(a+i);
                *(a+i) = temp;
            }
        }        
    }
}

//***************************** Display Function *******************************
//Description: Display and output array
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  Pointer Array values
//******************************************************************************

void prntAry(float *a, int s) {
    cout<<endl;
    for (int c=0; c<s; c++) {
        cout<<c+1<<".  $ "<<*(a+c)<<" "<<endl;
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
//Description: Modify Program 9-19 (the United Cause case study program) so 
//        the arrptr array is sorted in descending order instead of ascending 
//        order.
//Inputs:  Float values from user input
//Outputs:  Sorted list of donations in ascending order
//******************************************************************************

void hProb6(){
    cout<<"Homework - CASE STUDY MODIFICATION #2"<<endl<<endl;
    //Declare Variables
    float *donate = nullptr;  
    int size;
    char choice; 
    bool x=true;
    
    cout<<"Number of set donations: ";
    cin>>size;
    
    //Input Values
    donate = donFill(size);
    
    //Process by mapping inputs to outputs
    srtAryD(donate, size);
    
    //Output values
    cout<<endl<<"The donations sorted in descending order: "<<endl;
    prntAry(donate, size);
    
    delete [] donate;
    donate = 0;
    
    cout<<endl;
}

//***************************** Sort Function **********************************
//Description: Sort array ascending order
//Inputs:   No inputs but utilizes pointer argument and size
//Outputs:  No outputs
//******************************************************************************

void srtAryD(float *a, int n) {
    float temp;
    for(int c=0;c<n-1;c++){
        for(int i=c+1;i<n;i++){
            if(*(a+c)<*(a+i)){
                temp = *(a+c);
                *(a+c) = *(a+i);
                *(a+i) = temp;
            }
        }        
    }
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 7 ***********************************
//Description: In statistics, the mode of a set of values is the value that 
//          occurs most often or with the greatest frequency. Write a function 
//          that accepts as arguments the following:
//              A) An array of integers
//              B) An integer that indicates the number of elements in the 
//                 array
//              The function should determine the mode of the array. That is, it 
//          should determine which value in the array occurs most often. The 
//          mode is the value the function should return. If the array has no 
//          mode (none of the values occur more than once), the function should 
//          return −1. (Assume the array will always contain nonnegative 
//          values.)
//              Demonstrate your pointer prowess by using pointer notation 
//          instead of array notation in this function.
//Inputs:  Integers or random integers
//Outputs:  int - number of modes, frequency of modes & modes
//******************************************************************************

void hProb7(){
    cout<<"Homework - MODE FUNCTION"<<endl<<endl;
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
    
    cout<<endl;
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 8 **********************************
//Description: The local Driver’s License Office has asked you to write a 
// program that grades the written portion of the driver’s license exam. The 
// exam has 20 multiple choice questions. Here are the correct answers:
// 
//      1. A        6. B        11. A       16. C
//      2. D        7. A        12. C       17. C
//      3. B        8. B        13. D       18. A
//      4. B        9. C        14. B       19. D
//      5. C        10. D       15. D       20. B
// 
//   Your program should store the correct answers shown above in an array. It 
// should ask the user to enter the student’s answers for each of the 20 
// questions, and the answers should be stored in another array. After the 
// student’s answers have been entered, the program should display a message 
// indicating whether the student passed or failed the exam. (A student must 
// correctly answer 15 of the 20 questions to pass the exam.) It should then 
// display the total number of correctly answered questions, the total number of 
// incorrectly answered questions, and a list showing the question numbers of 
// the incorrectly answered questions.
// 
//      Input Validation: Only accept the letters A, B, C, or D as answers.
//Inputs:  char - letter answer per number
//Outputs:  score, mistakes, number of wrong answer and its right answer
//******************************************************************************

void hProb8(){
    cout<<"Homework - MEDIAN FUNCTION"<<endl<<endl;
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
    
    cout<<endl;
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

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 9 **********************************
//Description: Write a function that accepts an int array and the array’s size 
//        as arguments. The function should create a copy of the array, except 
//        that the element values should be reversed in the copy. The function 
//        should return a pointer to the new array. Demonstrate the function 
//        in a complete program.
//Inputs:  Integers
//Outputs:  Copied int array but reversed
//******************************************************************************

void hProb9(){
    cout<<"Homework - REVERSE ARRAY"<<endl<<endl;
    //Declare Variables
    int num, *array = nullptr, *copy = nullptr;
    
    cout<<"Number of Elements to Allocate: ";
    cin>>num;
    cout<<"\nGenerating "<<num<<" random numbers from 10-99..."<<endl;
    
    //Input Values
    //Process by mapping inputs to outputs
    array = alloc8(num);
    
    //Output values
    pntAry(array, num);
    copy=copyRev(array, num);
    pntAry(copy, num);
    
    delete [] array;
    delete [] copy;
    array = 0;
    copy = 0;
    
    cout<<endl;
}

//************************** Display Array Function ****************************
//Description: Display pointer array
//Inputs:   No inputs but utilizes integer argument and size
//Outputs:  The whole array of integer
//******************************************************************************

void pntAry(int *a, int n) {
    cout<<endl;
    for (int c=0; c<n; c++) {
        cout<<*(a+c)<<" ";
        if ((c+1)%10==0) cout<<endl;
    }
    cout<<endl;
}

//******************************* Copy Function ********************************
//Description: Reverse copy of array integers (not sorted)
//Inputs:   No inputs but utilizes integer argument and size
//Outputs:  Returns pointer to array
//******************************************************************************

int *copyRev(int *a, int n) {
    int *copy=nullptr, j=n;     //copy pointer, count
    copy=new int[n];
    for (int i=0; j>0; j--, i++) {
       *(copy+i)=*(a+(j-1));        
    }
    return copy;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 10 **********************************
//Description: Determine the mean average of a pointer array.
//Inputs:  integers or generated int random numbers
//Outputs:  Float mean average of pointer array
//******************************************************************************

void hProb10(){
    cout<<"Homework - CLASS Assignment MEAN AVERAGE"<<endl<<endl;
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
    
    cout<<endl;
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

