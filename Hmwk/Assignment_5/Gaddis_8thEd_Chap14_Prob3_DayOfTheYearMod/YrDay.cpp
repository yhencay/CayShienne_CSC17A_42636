/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "YrDay.h"
#include <string>
#include <iostream>
using namespace std;

YrMonth::YrMonth(string m, int d) {
    if (d<=0||d>31) {
         cout<<"\nDay does not exist. Terminating the program...\n\n"; 
    }
    else {       
        day=(m=="January")?d:(m=="February")?(31+d):(m=="March")?(59+d):
            (m=="April")?(90+d):(m=="May")?(120+d):(m=="June")?(151+d):
            (m=="July")?(181+d):(m=="August")?(212+d):(m=="September")?(243+d):
            (m=="October")?(273+d):(m=="November")?(304+d):(m=="December")?(334+d):0;
        cout<<"\nDay Before: ";
        if ((day-1)==0) {
            cout<<365;
        }
        else cout<<day-1;
        cout<<"\nDay: "<<day<<endl;
        cout<<"Day Ahead: "; 
        if ((day+1)==366) {
            cout<<1;
        }
        else cout<<day+1;
        cout<<endl;
    }
}