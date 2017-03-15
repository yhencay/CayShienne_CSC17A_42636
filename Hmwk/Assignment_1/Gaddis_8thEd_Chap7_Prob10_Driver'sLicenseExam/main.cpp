/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on March 5, 2017, 1:35 PM
 * Purpose: Homework Driver's License Exam
 * 
 *      Problem: The local Driver’s License Office has asked you to write a 
 * program that grades the written portion of the driver’s license exam. The 
 * exam has 20 multiple choice questions. Here are the correct answers:
 * 
 *      1. A        6. B        11. A       16. C
 *      2. D        7. A        12. C       17. C
 *      3. B        8. B        13. D       18. A
 *      4. B        9. C        14. B       19. D
 *      5. C        10. D       15. D       20. B
 * 
 *   Your program should store the correct answers shown above in an array. It 
 * should ask the user to enter the student’s answers for each of the 20 
 * questions, and the answers should be stored in another array. After the 
 * student’s answers have been entered, the program should display a message 
 * indicating whether the student passed or failed the exam. (A student must 
 * correctly answer 15 of the 20 questions to pass the exam.) It should then 
 * display the total number of correctly answered questions, the total number of 
 * incorrectly answered questions, and a list showing the question numbers of 
 * the incorrectly answered questions.
 * 
 *      Input Validation: Only accept the letters A, B, C, or D as answers.
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
    
    //Exit stage right! - This is the 'return 0' call
    return 0;
}

