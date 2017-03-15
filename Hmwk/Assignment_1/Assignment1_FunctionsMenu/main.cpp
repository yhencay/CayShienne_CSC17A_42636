/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on March 5, 2017, 1:08 AM
  Purpose:  Homework 1 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string> //String Library
#include <iomanip> //Format Library
#include <cmath> //Math Library
#include <cstdlib> //Standard Library
#include <ctime>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
const short PERCENT = 100;   //Percentage conversion
const int COLS = 30;      //2D Array Column

//Function Prototypes
void hProb1();
void hProb2();
void hProb3();
void hProb4();
void hProb5();
void hProb6();
void hProb7();
int count(char[][COLS], char, int); //Count how many characters in char array
void hProb8();
void hProb9();
void disAry (string[], int);   //Display or Print Array
void rowSwap (string[], int);   //Swap a whole row for sorting
void sortAry (string[], int);   //Sort Array alphabetically

//Executable code begins here!!!
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    bool x = true;
    
    //Loop on the menu
    do{    
        //Input values        
        cout<<"------------------------------------------------"<<endl;
        cout<<"                CHOOSE FROM THE LIST            "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"Type A : Chap 3 Prob 12 - TEMPERATURE CONVERSION"<<endl;
        cout<<"Type B : Chap 3 Prob 13 - CURRENCY"<<endl;
        cout<<"Type C : Chap 3 Prob 17 - MATH TUTOR"<<endl;
        cout<<"Type D : Chap 4 Prob  8 - COLOR MIXER"<<endl;
        cout<<"Type E : Chap 4 Prob 10 - DAYS IN MONTH"<<endl;
        cout<<"Type F : Chap 5 Prob 11 - POPULATION"<<endl;
        cout<<"Type G : Chap 7 Prob  6 - RAIN OR SHINE"<<endl;
        cout<<"Type H : Chap 7 Prob 10 - DRIVER'S LICENSE EXAM"<<endl;
        cout<<"Type I : Chap 8 Prob  7 - BINARY STRING SEARCH"<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"CHOICE: ";
        cin>>choice;
        cout<<endl;

        //Switch to determine the Problem
        switch(choice){
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
//Problem: Write a program that converts Celsius temperatures to 
// Fahrenheit temperatures. The formula is F = ((9*C)/5)+32;
//        F is the Fahrenheit temperature, and C is the Celsius temperature.
//Inputs:  Floats - temp in celsius
//Outputs:   Floats - temp in farenheit
//******************************************************************************

void hProb1(){
    cout<<"Homework - TEMPERATURE CONVERSION"<<endl<<endl;
    //Declare Variables
    float tempC,
          tempF;
    
    //Input Values
    cout<<"Let's convert Celsius to Farenheit!"<<endl<<endl;
    cout<<"Input Celsius Temperature: ";
    cin>>tempC;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    tempF = ((9 * tempC)/5 )+ 32;
    
    //Output values
    cout<<fixed<<setprecision(1);
    cout<<"The temperature "<<tempC<<"°C is converted to "<<tempF<<"°F."<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
//Description: Write a program that will convert U.S. dollar amounts to 
//          Japanese yen and to euros, storing the conversion factors in the 
//          constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR . To get the most 
//          up-to-date exchange rates, search the Internet using the term 
//          “currency exchange rate”. If you cannot find the most recent 
//          exchange rates, use the following:
//                  1 Dollar = 98.93 Yen
//                  1 Dollar = 0.74 Euros
//          Format your currency amounts in fixed-point notation, with two 
//          decimal places of precision, and be sure the decimal point is 
//          always displayed.
//Inputs:  float - dollar amount
//Outputs:  float - converted amount in euro and yen
//******************************************************************************

void hProb2(){
    cout<<"Homework - CURRENCY"<<endl<<endl;     
    //Declare Variables
    const float yenPerD = 98.93f, euPerD = 0.74f;       //Conversion amount
    float dollar, yen, euro;                            //User input and variable to hold result
    
    //Input Values
    cout<<"Enter US Dollar Amount: $";
    cin>>dollar;                            //Prompt user for amount
    
    //Process by mapping inputs to outputs
    yen = dollar*yenPerD;                  
    euro = dollar*euPerD;
    
    //Output values
    cout<<setprecision(2)<<fixed<<showpoint;
    cout<<"\nUS DOLLAR:\t$"<<dollar<<endl<<endl;
    cout<<"YEN:\t ¥"<<yen<<endl;                     //Display Results
    cout<<"EURO:\t €"<<euro<<endl;
       
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
//Description: Write a program that can be used as a math tutor for a young 
// student. The program should display two random numbers to be added, such as 
//       247
//     +129
// The program should then pause while the student works on the problem. When 
// the student is ready to check the answer, he or she can press a key and the 
// program will display the correct solution:
//       247
//     +129
//       376
//Inputs:  No inputs - generates random number
//Outputs:  Sum of generated numbers
//******************************************************************************

void hProb3(){
    cout<<"Homework - MATH TUTOR"<<endl<<endl;
    //Declare Variables
    srand(static_cast<unsigned int>(time(0)));
    unsigned short fadd, sadd;                  //First Addend & Second Addend
    int sum;
    string dummy;
        
    //Input Values
    fadd = (rand()%(65535-1+1))+1;              //Both are datatype short range!
    sadd = (rand()%(65535-1+1))+1;
    
    //Process by mapping inputs to outputs
    sum = fadd + sadd;
    cin.clear();
    getline(cin, dummy);
    //Output values
    cout<<"Try to solve!"<<endl<<endl;
    cout<<"            "<<setw(5)<<fadd<<endl;
    cout<<"          + "<<setw(5)<<sadd<<endl
        <<"           -------"<<endl<<endl;
    cout<<"Press enter for full answer!";
    cin.get();
    cout<<endl;
    cout<<"            "<<setw(5)<<fadd<<endl;
    cout<<"          + "<<setw(5)<<sadd<<endl; 
    cout<<"           -------"<<endl;
    cout<<"  Answer:   "<<setw(5)<<sum<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
//Description: The colors red, blue, and yellow are known as the primary 
// colors because they cannot be made by mixing other colors. When you mix two 
// primary colors, you get a secondary color, as shown here:
//          When you mix red and blue, you get purple.
//          When you mix red and yellow, you get orange.
//          When you mix blue and yellow, you get green.
//      Write a program that prompts the user to enter the names of two primary 
// colors to mix. If the user enters anything other than “red,” “blue,” or 
// “yellow,” the program should display an error message. Otherwise, the program 
// should display the name of the secondary color that results by mixing two 
// primary colors.
//Inputs:  String - colors for mixing
//Outputs:  String - mixed color result
//******************************************************************************

void hProb4() {
    cout<<"Homework - COLOR MIXER"<<endl<<endl;
    //Declare Variables
    string frsCol,              //First Color input
           scnCol,              //Second color input
           red = "red",         //Color to mix (red)
           blue = "blue",       //Color to mix (blue)
           yellow = "yellow",   //Color to mix (yellow)
           result;              //Result of the mixed colors
    
    //Input Values
    cout<<"Let's mix together primary colors (red, blue, yellow)."<<endl
        <<"You only get a secondary color when you mix two colors from above.\n"
        <<"If you enter other colors beside those three, you get an error!\n"
        <<"\nReminder: When you type, it must be in lowercase or you get an error."
        <<endl<<endl;
    cout<<"1st Color: ";
    cin>>frsCol;                    //Prompt user for input
    
    cout<<"2nd Color: ";
    cin>>scnCol;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    //Output values  
    if (frsCol == "red") {
        if (scnCol == "blue"){
            cout<<"After mixing red and blue, you get a purple!\n";
        }
        else if (scnCol == "yellow") {
            cout<<"After mixing red and yellow, you get an orange!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else if (frsCol == "blue") {
        if (scnCol == "red"){
            cout<<"After mixing blue and red, you get a purple!\n";
        }
        else if (scnCol == "yellow") {
            cout<<"After mixing blue and yellow, you get a green!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else if (frsCol == "yellow") {
        if (scnCol == "red"){
            cout<<"After mixing yellow and red, you get an orange!\n";
        }
        else if (scnCol == "blue") {
            cout<<"After mixing yellow and blue, you get green!\n";
        }
        else cout<<"INVALID INPUT!";
    }
    else {
        cout<<"INVALID INPUT!";
    }
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
//Description: Write a program that asks the user to enter the month (letting 
//          the user enter an integer in the range of 1 through 12) and the 
//          year. The program should then display the number of days in that 
//          month. Use the following criteria to identify leap years: 
//              1. Determine whether the year is divisible by 100. If it is, 
//              then it is a leap year if and only if it is divisible by 400. 
//                  For example, 2000 is a leap year but 2100 is not.
//              2. If the year is not divisible by 100, then it is a leap year 
//              if and if only it is divisible by 4. For example, 2008 is a 
//              leap year but 2009 is not.
// 
//          Here is a sample run of the program:
// 
//              Enter a month (1-12): 2 [ Enter]
//              Enter a year: 2008 [Enter]
//              29 days
//Inputs:  Int and Short - for year and month
//Outputs:  Equivalent days of month
//******************************************************************************

void hProb5(){
    cout<<"Homework - DAYS IN MONTH"<<endl<<endl;
    //Declare Variables
    unsigned int year;
    unsigned short month;
    
    //Input Values
    cout<<"Enter a month (1-12): ";
    cin>>month;
    cout<<"Enter a year: ";             //Prompt user for input
    cin>>year;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    //Output values
    if (month==1||month==3||month==5||month==7||month==8||month==10||month==12) cout<<"31 Days"<<endl;      //Normal days
    else if (month==4||month==6||month==9||month==11) cout<<"30 Days"<<endl;
    else if (month==2) {
        if (year%100==0&&year%400==0) cout<<"29 Days"<<endl;            //Determine leap years
        else if (!(year%100==0)&&year%4==0) cout<<"29 Days"<<endl;
        else cout<<"28 Days"<<endl;
    }  
    else cout<<"Invalid Input!"<<endl;          //Month has to be 1-12

    cout<<endl;    
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
//Description: Write a program that will predict the size of a population of 
//          organisms. The program should ask the user for the starting number 
//          of organisms, their average daily population increase (as a 
//          percentage), and the number of days they will multiply. A loop
//          should display the size of the population for each day. 
//              Input Validation: Do not accept a number less than 2 for the 
//                  starting size of the population.
//          Do not accept a negative number for average daily population 
//          increase. Do not accept a number less than 1 for the number of days 
//          they will multiply. 
//Inputs:  int for days and float for average percentage
//Outputs:  population increase of organisms based on input
//******************************************************************************

void hProb6(){
    cout<<"Homework - POPULATION"<<endl<<endl;
    //Declare Variables
    float ave, start;      //Average daily percentage, starting number
    int days;              //Days to multiply
    
    //Input Values
    cout<<"Input following: "<<endl<<endl;
    cout<<"Starting number of organisms: ";
    cin>>start;
    cout<<"Average daily population increase (percentage): ";
    cin>>ave;
    cout<<"Number of days they will multiply: ";
    cin>>days;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    ave=ave/PERCENT;        //Convert input to decimal
    
    //Output values
    if (start<2) cout<<"Starting number cannot be less than 2!"<<endl;                  //Input Validation
    else if (ave<0) cout<<"Daily population increase cannot be negative!"<<endl;
    else if (days<1) cout<<"Number of days to multiply cannot be less than 1!"<<endl;
    else {
        cout<<"Start  \t\t"<<start<<endl;
        cout<<setprecision(2)<<fixed<<showpoint;            //Loop for the program
        for (int c=0;c<days;c++) {                          //Calculates organisms and displays
            start+=start*ave;                               //how much they grow
            cout<<"Day "<<c+1<<"\t\t"<<start<<endl;
        }
    }
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 7 ***********************************
//Description: An amateur meteorologist wants to keep track of weather 
//          conditions during the past year’s three-month summer season and has 
//          designated each day as either rainy (‘R’), cloudy (‘C’), or 
//          sunny (‘S’). Write a program that stores this information in a 
//          3 × 30 array of characters, where the row indicates the month 
//          (0 = June, 1 = July, 2 = August) and the column indicates the day 
//          of the month. Note that data are not being collected for the 31st 
//          of any month. The program should begin by reading the weather data 
//          in from a file. Then it should create a report that displays, for
//          each month and for the whole three-month period, how many days were 
//          rainy, how many were cloudy, and how many were sunny. It should 
//          also report which of the three months had the largest number of 
//          rainy days. Data for the program can be found in the 
//          RainOrShine.txt file.
//Inputs:  Input from file RainOrShine.txt
//Outputs:  Output - results of count and rainiest month
//******************************************************************************

void hProb7(){
    cout<<"Homework - RAIN OR SHINE"<<endl<<endl;
    //Declare Variables
    const int ROWS = 3;                 //Row Size
    char table[ROWS][COLS] = {};        //2D Character array
    char rain = 'R', cloud = 'C', sun = 'S';    //Character equivalent
    int juneR, juneS, juneC, julyR, julyS,
        julyC, augR, augS, augC, highest;   //Variable for results of counting
    
    //Input Values
    //Instantiate and Open Files
    ifstream in;                   
    in.open("RainOrShine.txt");
    
    for (int c=0; c<ROWS; c++) {
        for (int i=0; i<COLS; i++) {
            in>>table[c][i];
        }
    }
    
    in.close();
    
    cout<<"\t\tCHART"<<endl<<endl;
    cout<<"Day\t";
    for (int d=0;d<COLS;d++) cout<<d+1<<setw(4);        //Day Count
    cout<<endl;
    
    //Display Array
    for (int c=0; c<ROWS; c++) {
        c==0?cout<<"June\t":c==1?cout<<"July\t":cout<<"August\t";       //Display Month per count
        for (int i=0; i<COLS; i++) {
            cout<<table[c][i]<<setw(4);
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Process by mapping inputs to outputs
    juneR = count(table, rain, 0);
    juneS = count(table, sun, 0);
    juneC = count(table, cloud, 0);
    julyR = count(table, rain, 1);             //Call function for counting of
    julyS = count(table, sun, 1);              //rainy, sunny, cloudy per month
    julyC = count(table, cloud, 1);
    augR = count(table, rain, 2);
    augS = count(table, sun, 2);
    augC = count(table, cloud, 2);
      
    //Output values
    cout<<"\tJUNE\tJULY\tAUGUST"<<endl;
    cout<<"Rainy: \t"<<juneR<<"\t"<<julyR<<"\t"<<augR<<endl;
    cout<<"Sunny: \t"<<juneS<<"\t"<<julyS<<"\t"<<augS<<endl;
    cout<<"Cloudy:\t"<<juneC<<"\t"<<julyC<<"\t"<<augC<<endl;
    cout<<endl;
    
    //Determine which month has the most rainy days and output
    if (juneR>julyR&&juneR>augR) cout<<"LARGEST NUMBER OF RAINY DAYS: JUNE, "<<juneR<<" Days"<<endl;        
    else if (julyR>juneR&&julyR>augR) cout<<"LARGEST NUMBER OF RAINY DAYS: JULY, "<<julyR<<" Days"<<endl;
    else cout<<"LARGEST NUMBER OF RAINY DAYS: AUGUST, "<<augR<<" Days"<<endl; 
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//**************************** Count Function **********************************
//Description: Count how many times an argument occurs in the array
//Inputs:   No inputs but utilizes input file from main
//Outputs:  Returns how many the argument occurred
//******************************************************************************

int count(char table[][COLS], char w, int r) {
    int rec = 0;                    //Static Variable
    for (int c=0; c<COLS; c++) {
        if (table[r][c]==w) rec++;      //Increment if argument occurred
    }
    return rec;
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
    cout<<"Homework - DRIVER'S LICENSE EXAM"<<endl<<endl;
    //Declare Variables
    const int SIZE = 21;        //Set array size to 21-1
    char right[SIZE]= { '0', 'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C',   //Array for the right answers
                        'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 
                        'D', 'B' };     //Set 0 to Subscript 0
    char answers[SIZE];                 //Array for user's answers
    int wrongs[SIZE] = {};              //Array for storing mistakes
    short rAns = 0,             //Count of right answers
          wAns = 0,             //Count of wrong answers
          count,                //Loop counter
          total;                //Count for mistakes and right answers
    
    cout<<"Type in your answer for the corresponding number in the exam."<<endl<<endl;
    
    //Input Values
    for (count = 1; count <SIZE; count++) {
        do {
            cout<<count<<". ";                  //Prompt user to input answers from 1-20
            cin>>answers[count];                //Loop until user input is not A, B, C or D
            
            if (!(answers[count] == 'A' || answers[count] == 'B' || 
                answers[count] == 'C' || answers[count] == 'D')) {
                cout<<"\nYou can only answer with capital letters A, B, C or D. Try again!\n\n";
            } 
        } while (!(answers[count] == 'A' || answers[count] == 'B' || answers[count] == 'C' || answers[count] == 'D'));
    }
    
    //Process by mapping inputs to outputs
    for (count = 1; count < SIZE; count++) {            //Compare array elements
        if (right[count] == answers[count]) rAns++;     //If right answers and user answer matched, increment right answers
        else {              
            wAns++;                                     //If not, increment wrong answers
            wrongs[count] = count;                      //Store number of wrong answer to wrongs array
        }            
    }
    
    total = (rAns >= 15)?(SIZE-1)-rAns:(SIZE-1)-wAns;      //Calculate total mistake and/or total score if score is greater than 15 or not

    //Output values    
    if (rAns >= 15) {           //Display Passed if array matched are greater than or equal to 15. 
        cout<<"\nCongratulations! You passed with a score of "<<rAns<<" out of "<<(SIZE-1)<<" questions!"<<endl; 
        cout<<"You have "<<total<<" mistake(s)!"<<endl<<endl;   //Display mistakes if there are some
    }
    else {          //Display Failed if array matched is less than 15
        cout<<"\nSorry! You failed. Your score is "<<total<<" out of "<<(SIZE-1)<<" questions."<<endl;               
        cout<<"You got "<<wAns<<" wrong answers out of "<<(SIZE-1)<<" questions."<<endl<<endl; //Display mistakes
    }
    
    if (wAns > 0) {  //Display the numbers user got wrong and display the right answer corresponding to that number
        cout<<"Here are the correct answers for the numbers you missed: "<<endl<<endl;
        for (count = 0; count<SIZE;count++) {
            if (wrongs[count] == 0) cout<<"\0";
            else cout<<wrongs[count]<<" "<<right[count]<<endl;        
        }
    }
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 9 **********************************
//Description: Modify the binarySearch function presented in this chapter so 
//          it searches an array of strings instead of an array of int s. Test 
//          the function with a driver program. Use Program 8-8 as a skeleton 
//          to complete. (The array must be sorted before the binary search 
//          will work.)
//Inputs:  Embedded input of strings
//Outputs:  alphabetical order of string arrays
//******************************************************************************

void hProb9(){
    cout<<"Homework - BINARY STRING SEARCH"<<endl<<endl;
    //Declare Variables
    const int SIZE = 20;        //Size of array or number of names to initialize
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                          "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                          "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",        //Data input in array
                          "Looney, Joe", "Wolfe, Bill", "James, Jean",
                          "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                          "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                          "Pike, Gordon", "Hollan, Beth"};
    
    //Display Values
    cout<<"-------------------------"<<endl;
    cout<<"     Data from Array"<<endl;              //Display initial array
    cout<<"-------------------------"<<endl;
    disAry(names, SIZE);
    
    //Process by mapping inputs to outputs
    sortAry(names, SIZE);                       //Sort array using function
    
    //Output values
    cout<<"-------------------------"<<endl;
    cout<<"      Sorted Array"<<endl;                 //Display sorted array in alphabetical order
    cout<<"-------------------------"<<endl;
    disAry(names, SIZE);
    cout<<endl;
}

//**************************** Display Function ********************************
//Description: Display Array
//Inputs:   No inputs
//Outputs:  Displays array
//******************************************************************************

void disAry (string n[], int s) {
    cout<<"Number\tNames"<<endl;
    for (int c=0; c<s; c++) {
        cout<<setw(3)<<c+1<<"\t"<<n[c]<<endl;
    }
    cout<<endl;
}

//*************************** Row Swap Function ********************************
//Description: Swaps the whole row of a string input
//Inputs:   No inputs
//Outputs:  No outputs
//******************************************************************************

void rowSwap (string n[], int c) {
    string temp = ""; //string temp for swapping
    temp = n[c];      //assign current element to temp
    n[c] = n[c+1];    //change current element to next element
    n[c+1] = temp;    //change temp to current element that was changed
}

//*************************** Sort Array Function ******************************
//Description: Sort string array
//Inputs:   No inputs but utilizes array from main
//Outputs:  No outputs but sorts array
//******************************************************************************

void sortAry (string n[], int s) {
    bool swap;          
    do {
        swap = false;   //remains false if no swapped happened in loop
        for (int c=0; c<s-1; c++) {  
            if (n[c]>n[c+1]) {   //compare current element to next one
                rowSwap (n, c);  //if true, swap whole row by calling rowSwap function
                swap = true;     //keep swap true to continue loop
            }
        }
    } while (swap);
}