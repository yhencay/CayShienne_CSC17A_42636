/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "NumCls.h"
using namespace std;

Numbers::Numbers(int num) {
    number=num;
    hundred=" hundred ";
    thousnd=" thousand ";
}
string Numbers::wrdAry[20] = {"zero", "one", "two", "three", "four", "five", "six",
                  "seven", "eight", "nine", "ten", "eleven", "twelve", 
                  "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                  "eighteen", "nineteen"};

void Numbers::prntWrd() {
    int amount=number, amount2, amount3;       //Amount for extraction
    char s1000, s100, s10, s1;      //variable to convert in switch case
    string word="";
    s1000 = (amount-(amount%1000))/1000;  //Conversion to take the amount in Thousandth place
    amount2 = (amount - (s1000*1000));
    s100 = (amount2-(amount2%100))/100;   //Conversion to take the amount in Hundredth place
    amount3 = (amount2 - (s100*100));
    s10 = (amount3-(amount3%10))/10;          //Conversion to take the amount in Tenth place
    s1 = (amount3 - (s10*10));                 //Conversion to take the amount in One's
    
    switch (s10) {                              //Switch evaluate in Tens
        case 9:word+="ninety "; break;
        case 8:word+="eighty "; break;
        case 7:word+="seventy "; break;
        case 6:word+="sixty "; break;
        case 5:word+="fifty "; break;
        case 4:word+="forty "; break;
        case 3:word+="thirty "; break;
        case 2:word+="twenty "; break;
        case 1: { s10 = ((s10*10) + (amount3%10));      //Switch evaluate if it's past range 10 and less
            switch (s10) {                              //than 20
                case 19:word+="nineteen ";break;
                case 18:word+="eighteen ";break;
                case 17:word+="seventeen ";break;
                case 16:word+="sixteen ";break;
                case 15:word+="fifteen ";break;
                case 14:word+="fourteen ";break;
                case 13:word+="thirteen ";break;
                case 12:word+="twelve ";break;
                case 11:word+="eleven ";break;
                case 10:word+="ten ";break;
                default: cout<<"Error!"; break;
            }
        }; break;
        case 0:break;
        default: cout<<"BAD AMOUNT!"<<endl;
    }
    s10 = (amount3-(amount3%10))/10;              //Repeat amount for evaluation in one's

    switch (s1) {
        case 9:word+="nine "; break;
        case 8:word+="eight "; break;
        case 7:word+="seven "; break;
        case 6:word+="six "; break;
        case 5:word+="five "; break;
        case 4:word+="four "; break;
        case 3:word+="three "; break;
        case 2:word+="two "; break;
        case 1:word+="one "; break;
        case 0:break;
        default: cout<<"BAD AMOUNT!"<<endl;
    }
    if (s1000>0) {
        cout<<wrdAry[s1000]<<thousnd;
        if (s100>0) cout<<wrdAry[s100]<<hundred;
        if (s10==1) {
            s10 = ((s10*10) + (amount3%10));
            cout<<wrdAry[s10];
            s10 = (amount3-(amount3%10))/10;
        }
        else cout<<word;
    }
    else if (s100>0) {
        cout<<wrdAry[s100]<<hundred;
        if (s10==1) {
            s10 = ((s10*10) + (amount3%10));
            cout<<wrdAry[s10];
            s10 = (amount3-(amount3%10))/10;
        }
        else cout<<word;
    }
    else cout<<word;
}