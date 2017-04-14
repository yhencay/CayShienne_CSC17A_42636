/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on April 4, 2017, 4:14 PM
  Purpose:  Homework 4 Menu
 */

//System Libraries
#include <iostream> //Input Output Library
#include <string>   //String Library
#include <cstring>  //Character String
#include <fstream>  //Input Output File
#include <iomanip>  
using namespace std;

//User Libraries

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from system of units to another
             
//Function Prototypes
void hProb1();
short cntChar(char [], int );       //Count number of characters
void hProb2();
void bckChar(char *, int);          //Convert characters backwards
void hProb3();
short wrdChar(char *, int);         //Count words number in c-string
void hProb4();
void hProb5();
void hProb6();
void hProb7();
void hProb8();
void hProb9();
void hProb10();

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
        cout<<"Type A : CH. 10 Problem 1 - STRING LENGTH"<<endl;
        cout<<"Type B : CH. 10 Problem 2 - BACKWARD STRING"<<endl;
        cout<<"Type C : CH. 10 Problem 3 - WORD COUNTER"<<endl;
        cout<<"Type D : CH. 10 Problem 4 - AVERAGE NUMBER OF LETTERS"<<endl;
        cout<<"Type E : CH. 10 Problem 8 - SUM OF DIGITS IN A STRING"<<endl;
        cout<<"Type F : CH. 12 Problem 1 - FILE HEAD PROGRAM"<<endl;
        cout<<"Type G : CH. 12 Problem 2 - FILE DISPLAY PROGRAM"<<endl;
        cout<<"Type H : CH. 12 Problem 3 - PUNCH LINE"<<endl;
        cout<<"Type I : CH. 12 Problem 4 - TAIL PROGRAM"<<endl;
        cout<<"Type J : CH. 12 Problem 5 - LINE NUMBERS"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
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
// Problem: Write a function that returns an integer and accepts a 
//      pointer to a C-string as an argument. The function should count the 
//      number of characters in the string and return that number. Demonstrate 
//      the function in a simple program that asks the user to input a string, 
//      passes it to the function, and then displays the function’s return value.
//Inputs:  Characters
//Outputs:   Number of characters
//******************************************************************************

void hProb1(){
    cout<<"Homework - STRING LENGTH"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN
    const int SIZE = 80;        //Size of array
    char input[SIZE];           //C-string array
    short numChar;              //Number of characters
    
    //Input Values
    cout<<"Enter 1-79 number of characters including spaces. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: Spaces are not counted in character count."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);       //Get the whole line of character input into c-string
    
    //Process by mapping inputs to outputs
    numChar = cntChar(input, SIZE);     //Call function and assign value to numChar
    
    //Output values
    cout<<"\nLength of character(s) entered: "<<numChar<<" character(s)"<<endl<<endl;
}

//************************** Count Strings Function ****************************
//Description: Counts how many number of characters in a character array
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Length of characters in an input
//******************************************************************************

short cntChar(char a[], int s) {
    short cnt=0;                                //Set count for number of characters
    for (int i=0; i<s && a[i]!='\0'; i++) {     //Continue loop if i is less than s and array value is not equal to '\0'
        cnt++;                                  //Increment count
        if (a[i]==' ') cnt--;                   //if array value is equivalent to a space, decrement count
    }
    if (a[0]=='\0') cnt=0;                      //If array value is empty, set count to 0
    return cnt;                                 //Return count value
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 2 ***********************************
// Problem: Write a function that accepts a pointer to a C-string as an argument
//      and displays its contents backward. For instance, if the string argument 
//      is “ Gravity ” the function should display “ ytivarG ”. Demonstrate the 
//      function in a program that asks the user to input a string and then 
//      passes it to the function.
//Inputs:  Characters
//Outputs:   Backward of characters input
//******************************************************************************

void hProb2(){
    cout<<"Homework - BACKWARD STRING"<<endl<<endl; 
     //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN
    const int SIZE = 80;        //Size of array
    char data[SIZE];            //Declare C-string array
    
    //Input Values
    cout<<"Enter 1-79 number of characters. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: Data will be converted backwards."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(data, SIZE);    //Get the whole line of character input into c-string
    
    //Process by mapping inputs to outputs

    //Output values
    cout<<"\nBackwards: ";
    bckChar(data, SIZE);        //Call function and display backward equivalent of user input
    
    cout<<endl;
}

//************************* Backward Output Function ***************************
//Description: Displays a user input C-string backwards
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Backward of the content array
//******************************************************************************

void bckChar(char *d, int s) {
    short cnt=0;                                //Declare a counter for number of characters in the string
    for (int i=0; i<s && d[i]!='\0'; i++) {     //Loop to count how many characters there are in c-string
        cnt++;                                  //Increment count
    }
    if (d[0]=='\0') cnt=0;                      //If c-string is empty, set count to 0
    for (int c=cnt; c>=0; c--) {                //Set counter to count. 
        cout<<*(d+c);                           //Display input backwards as long as counter remains greater than or equal to 0
    }                                           //Decrement counter once fulfilled
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 3 ***********************************
// Problem: Write a function that accepts a pointer to a C-string as an argument
//      and returns the number of words contained in the string. For instance, 
//      if the string argument is “Four score and seven years ago” the function 
//      should return the number 6. Demonstrate the function in a program that 
//      asks the user to input a string and then passes it to the function. The 
//      number of words in the string should be displayed on the screen. 
//      Optional Exercise: Write an overloaded version of this function that 
//      accepts a string class object as its argument.
//Inputs:  Characters
//Outputs:  Word Count
//******************************************************************************

void hProb3(){
    cout<<"Homework - WORD COUNT"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN
    const int SIZE = 80;        //Size of array
    char input[SIZE];           //Declare a c-string array
    short numWrd;               //Number of words
    
    //Input Values
    cout<<"Enter 1-79 number of characters. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: We will calculate how many words there are."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);   //Get the whole line of character input into c-string
    
    //Process by mapping inputs to outputs
    numWrd = wrdChar(input, SIZE);      //Call function and assign value to numWrd
    
    //Output values
    cout<<"\nWord Count: "<<numWrd<<" word(s)"<<endl<<endl;
    
    cout<<endl;
}

//**************************** Word Count Function *****************************
//Description: Counts how many words are the in a C-string array
//Inputs:   No inputs but utilizes char array as argument
//Outputs:  Number of words in a C-string array
//******************************************************************************

short wrdChar(char *i, int s) {
    short cnt=0;                                //Set count for spaces
    for (int c=0; c<s && i[c]!='\0'; c++) {     //Loop the whole c-string array
        if (i[c]==' ') cnt++;                   //If a space is encountered increment count
    }
    if (i[0]=='\0') cnt=0;                      //If array is empty, set count to 0
    else cnt+=1;                                //Add one to count
    return cnt; 
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 4 ***********************************
// Problem: Modify the program you wrote for Problem 3 (Word Counter), so it 
//      also displays the average number of letters in each word.
//Inputs:  Characters
//Outputs:  Average number of letters
//******************************************************************************

void hProb4() {
    cout<<"Homework - AVERAGE NUMBER OF LETTERS"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');          //Clear CIN
    const int SIZE = 80;            //Size of array
    char input[SIZE];               //Declare C-string array
    float ave;                      //Average number of letters
    short numWrd, numChar;          //Number of words and number of characters
    
    //Input Values
    cout<<"Enter 1-79 number of characters including spaces. Characters after 79th will be ignored!"<<endl;
    cout<<"NOTE: We will calculate the average number of letters (excluding spaces)."<<endl<<endl;
    cout<<"Input: ";
    cin.getline(input, SIZE);       //Get the whole line of character input into c-string
    
    //Process by mapping inputs to outputs
    numChar = cntChar(input, SIZE);     //Call function and assign value to number of characters
    numWrd = wrdChar(input, SIZE);      //Call function and assign value to number of words
    ave = (static_cast<float>(numChar)/numWrd);     //Calculate average by converting numChar to float and dividing it by numWrd
    
    //Output values
    cout<<"\nCharacter Count: "<<numChar<<" character(s)"<<endl;
    cout<<"Word Count: "<<numWrd<<" word(s)"<<endl<<setprecision(3);
    cout<<"Average Number of Letters: "<<ave<<" letter(s) per word"<<endl<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 5 ***********************************
// Problem: Write a program that asks the user to enter a series of single digit
//      numbers with nothing separating them. Read the input as a C-string or a
//      string object. The program should display the sum of all the single-digit
//      numbers in the string. For example, if the user enters 2514, the program
//      should display 12, which is the sum of 2, 5, 1, and 4. The program 
//      should also display the highest and lowest digits in the string.
//Inputs:  Characters
//Outputs:  Sum of character inputs
//******************************************************************************

void hProb5(){
    cout<<"Homework - SUM OF DIGITS IN A STRING"<<endl<<endl;
     //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN
    const int SIZE = 100;       //Size of array
    char num[SIZE];             //Declare C-string array
    int total=0;                //Total of digits in c-string
    
    //Input Values
    cout<<"Note: Maximum length is 100. Excess Input is ignored."<<endl
        <<"      Only input numbers 1-9!"<<endl<<endl;
    cout<<"Input Number: ";
    cin.getline(num, SIZE);     //Get the whole line of character input into c-string
    
    //Process by mapping inputs to outputs
    int low=(num[0]-'0'), high=(num[0]-'0');            //Assign set value to high and low to determine it
    
    for (int i=0;i<strlen(num); i++) {                  //Loop to get total and determine highest and lowest
        total+=(num[i]-'0');                            //digit in c-string array
        if ((num[i]-'0')<low) low=(num[i]-'0');         //Use ASCII Arithmetic to convert char to int
        if ((num[i]-'0')>high) high=(num[i]-'0');
    }
    
    //Output values
    cout<<"\nTotal: "<<total<<endl;
    cout<<"Highest: "<<high<<endl;
    cout<<"Lowest: "<<low<<endl;
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
// Problem: Write a program that asks the user for the name of a file. The
//      program should display the first 10 lines of the file on the screen (the
//      “head” of the file). If the file has fewer than 10 lines, the entire file
//      should be displayed, with a message indicating the entire file has been
//      displayed.
//Inputs:  Read from file
//Outputs:  First 10 Lines of a file
//******************************************************************************

void hProb6(){
    cout<<"Homework - FILE HEAD PROGRAM"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN 
    string hold, still;         //Variable to hold string from file
    int cnt=0;                  //Set count for number of lines the file has
    
    //Input Values
    fstream file;
    file.open("file.txt", ios::in);         //Open file
    
    //Process by mapping inputs to outputs
    while(file) {                       //while file is true
        getline(file, hold);            //Assign every line to string variable
        cnt++;                          //Increment count
    }
    cnt--;                              //Decrement count once for exact number of lines
    file.close();                           //Close file
    
    //Output values
    file.open("file.txt", ios::in);     //Open file again
    if (cnt<10) {                       //If count is less than 10, show every line and indicate it as it is
        cout<<"Displaying "<<cnt<<" lines from file!"<<endl<<endl;
        for (int i=0; i<cnt; i++) {
        getline(file, still);
        cout<<still<<endl;
        }
        cout<<"\nThe content has less than ten lines!"<<endl;
    }
    else {                              //If not, show the first 10 lines of the file and indicate it as it is
        cout<<"Displaying 10 lines from file!"<<endl<<endl;
        for (int i=0; i<10; i++) {
        getline(file, still);
        cout<<still<<endl;
        }
        cout<<"\nThe content has atleast ten lines!"<<endl;
    }
    file.close();       //Close file
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 6 ***********************************
// Problem: Write a program that asks the user for the name of a file. The
//      program should display the contents of the file on the screen. If the 
//      file’s contents won’t fit on a single screen, the program should display 
//      24 lines of output at a time, and then pause. Each time the program 
//      pauses, it should wait for the user to strike a key before the next 24 
//      lines are displayed.
//Inputs:  Read from file
//Outputs:  First 24 lines of file if it's more than 24 lines
//******************************************************************************

void hProb7(){
    cout<<"Homework - FILE DISPLAY PROGRAM"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');          //Clear CIN
    string fylName, hold;           //Variable to hold string from file
    int cnt=0;                      //Set to count number of lines the file has
    char press='\0';                //for pressing enter key
	
    //Input Values
    cout<<"Choose file to open:"<<endl<<endl;
    cout<<"- One\n- Two\n- Three\n"<<endl;
    cout<<"CHOICE: ";
    cin>>fylName;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    fstream file;           
    file.open(fylName+".txt", ios::in);     //Open file   
    if(file) {                          //If file exist
        while(file) {                   //Count every line that the file has
            getline(file, hold);
            cnt++;
        }
        cnt--;                          //Decrement once to get exact number
    file.close();                       //Close file
    
    //Output Values
    file.open(fylName+".txt", ios::in); //Open file again
        for (int i=0;i<cnt;i++) {       //Show every line of file
            getline(file, hold);        //Assign every line to string variable
            cout<<hold<<endl;
            if ((i+1)%24==0) {          //If it's already 24 lines, prompt user to press enter key to view more
                cout<<"\nPress enter key to continue!"<<endl<<endl;
                cin.get(press);
                cin.ignore(256, '\n');      //clear CIN again
                cin.clear();
            }
        }
    file.close();           //Close file
    }
    
    else {
        cout<<"\nERROR! File does not exist!"<<endl<<endl;      //If it doesn't exist, display error
    }
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 8 ***********************************
// Problem: Write a program that reads and prints a joke and its punch line from 
//      two different files. The first file contains a joke, but not its punch 
//      line. The second file has the punch line as its last line, preceded by 
//      “garbage.” The main function of your program should open the two files 
//      and then call two functions, passing each one the file it needs. The 
//      first function should read and display each line in the file it is 
//      passed (the joke file). The second function should display only the last 
//      line of the file it is passed (the punch line file). It should find this 
//      line by seeking to the end of the file and then backing up to the 
//      beginning of the last line. Data to test your program can be found in 
//      the joke.txt and punchline.txt files.
//Inputs:  Read from file
//Outputs:  A joke and the punch line
//******************************************************************************

void hProb8(){
    cout<<"Homework - PUNCH LINE"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');                  //Clear CIN
    fstream joke;
    fstream punch;
    string hold="", still="", word="";      //Assign string variable to hold lines from file
    char sp='\0';                           //For character in every line from file
    
    //Input Values
    joke.open("joke.txt", ios::in);         //Open joke file
    while (joke){                           //Show every line from file until it ends
        getline(joke, still);
        cout<<still<<endl;
    }
    
    //Process by mapping inputs to outputs
    cout<<"Press enter twice to continue!"<<endl;        //Prompt user to press enter key
    cin.ignore(256, '\n');                          //Clear CIN
    cin.get();
    
    //Output values
    punch.open("punchline.txt", ios::in);           //Open punchline file
    for (int i=1; sp!='\n'; i++) {                  //Loop until the the last line of file has encountered '\n'
        punch.seekg(-i, ios::end);                  //Seek position negative value to the index beginning in the end
        punch.get(sp);                              //Get character
    }
    getline(punch, word);                           //Get the whole line and assign to variable string
    cout<<word<<endl;                               //Display the punch line which is the last line from file
    
    joke.close();                               //Close joke file
    punch.close();                              //Close punchline file
    
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 9 ***********************************
// Problem: Write a program that asks the user for the name of a file. The 
//      program should display the last 10 lines of the file on the screen (the
//      “tail” of the file). If the file has fewer than 10 lines, the entire file
//      should be displayed, with a message indicating the entire file has been 
//      displayed.
//Inputs:  Read from file
//Outputs:  Last 10 Lines of a file
//******************************************************************************

void hProb9(){
    cout<<"Homework - TAIL PROGRAM"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');              //Clear CIN
    string hold, still;                 //Assign variable to hold string
    int cnt=0;                          //Set to count lines from a file
    
    //Input Values
    fstream file;
    file.open("data.txt", ios::in);         //Open data file
    
    //Process by mapping inputs to outputs
    while(file) {                       //Count every line of file until the end
        getline(file, hold);            //Increment count for every line
        cnt++;
    }
    cnt--;                              //Decrement count once to get exact number
    file.close();                       //Close file
    
    //Output values
    file.open("data.txt", ios::in);     //Open data file again
    if (cnt<10) {                       //If count is less than 10
        cout<<"Displaying "<<cnt<<" lines of a file!"<<endl<<endl;
        for (int i=0; i<cnt; i++) {
            getline(file, still);           //Display all lines from file
            cout<<still<<endl;
        }
        cout<<"\nThe content has less than ten lines!"<<endl;       //Indicate how many lines it really was
    }
    else {
        cout<<"Displaying the last 10 lines from file!"<<endl<<endl;        //If count is more than 10
        for (int i=0; i<cnt; i++) {         //Assign index to 0 and continue loop until index is less than count
            if (i<(cnt-10)) {               //if index is less than number of count minue=s 10
                getline(file, still);       //Skip showing
            }
            else {                          //If not, display the line
                getline(file, still);
                cout<<still<<endl;
            }
        }
        cout<<"\nThe content has "<<cnt<<" lines total!"<<endl;     //Indicate total number of lines
    }
    file.close();               //Close file
        
    cout<<endl;
}

//345678901234567890123456789012345678901234567890123456780123456789012345678901
//*********************** Homework Problem 10 ***********************************
// Problem: (This assignment could be done as a modification of the program in
//      Programming Challenge 2.) Write a program that asks the user for the 
//      name of a file. The program should display the contents of the file on 
//      the screen. Each line of screen output should be preceded with a line 
//      number, followed by a colon. The line numbering should start at 1.
//Inputs:  Read from file
//Outputs:  Line number before every line from file
//******************************************************************************

void hProb10(){
    cout<<"Homework - LINE NUMBER"<<endl<<endl;
    //Declare Variables
    cin.ignore(256, '\n');      //Clear CIN
    string fylName, hold;       //Assign string variable to hold lines from file
    int cnt=0;                  //Set count for number of lines
    char press='\0';            //Prompt user to press enter key
	
    //Input Values
    cout<<"Choose file to open:"<<endl<<endl;
    cout<<"- One\n- Two\n- Three\n"<<endl;
    cout<<"CHOICE: ";                       //Prompt user to choose which file to open
    cin>>fylName;
    cout<<endl;
    
    //Process by mapping inputs to outputs
    fstream file;
    file.open(fylName+".txt", ios::in);     //Open file
    if(file) {                              //If choice exists, proceed
        while(file) {                       //Loop until end of file
            getline(file, hold);        
            cnt++;                          //Count every line there is
        }
        cnt--;                              //Decrement count once to get exact number
    file.close();                           //Close file
    
    //Output Values
    file.open(fylName+".txt", ios::in);     //Open file again
        for (int i=0;i<cnt;i++) {           //Show every line in loop
            getline(file, hold);
            cout<<i+1<<": "<<hold<<endl;    //Add a number line and a colon
            if ((i+1)%24==0) {              //If lines gets to 24th line, prompt user to press enter key
                cout<<"\nPress enter key to continue!"<<endl<<endl;
                cin.get(press);
                cin.ignore(256, '\n');      //Clesr CIN
                cin.clear();
            }
        }   
    file.close();           //Close file
    }
    
    else {              //If file doesn't exist, display error
        cout<<"\nERROR! File does not exist!"<<endl<<endl;
    }
    
    cout<<endl;
}
