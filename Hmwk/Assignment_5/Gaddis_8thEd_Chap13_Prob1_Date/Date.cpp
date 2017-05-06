/* 
  File:   main.cpp
  Author: Shienne Cay
  Created on May 4, 2017, 1:15 PM
  Purpose:  Date Class Implementation
 */

#include "Date.h"

Date::Date(int m, int d, int y) {
    month=m;
    day=d;
    year=y;
    if (month==1) wMon="January";
    else if (month==2) wMon="February";
    else if (month==3) wMon="March";
    else if (month==4) wMon="April";
    else if (month==5) wMon="May";
    else if (month==6) wMon="June";
    else if (month==7) wMon="July";
    else if (month==8) wMon="August";
    else if (month==9) wMon="September";
    else if (month==10) wMon="October";
    else if (month==11) wMon="November";
    else wMon="December";
}

void Date::prntD8() {
    cout<<endl<<month<<"/"<<day<<"/"<<year<<endl;
    cout<<wMon<<" "<<day<<", "<<year<<endl;
    cout<<day<<" "<<wMon<<" "<<year<<endl;
}