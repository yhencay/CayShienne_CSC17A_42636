/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "DayYr.h"
using namespace std;

DayOfYr::DayOfYr(int n) {
    input=n;
    day=getDate();
    month=getMon();
}

int DayOfYr::getDate() {
    int d=0;
    d=(input<=31)?input:(input<=59)?input-31:(input<=90)?input-59:
      (input<=120)?input-90:(input<=151)?input-90:(input<=181)?input-151:
      (input<=212)?input-181:(input<=243)?input-212:(input<=273)?input-212:
      (input<=304)?input-273:(input<=334)?input-304:(input<=365)?input-334:0;
    return d;
}

string DayOfYr::getMon() {
    string mon="";
    mon=(input<=31)?"January":(input<=59)?"February":(input<=90)?"March":
      (input<=120)?"April":(input<=151)?"May":(input<=181)?"June":
      (input<=212)?"July":(input<=243)?"August":(input<=273)?"September":
      (input<=304)?"October":(input<=334)?"November":(input<=365)?"December":"\0";
    return mon;
}

void DayOfYr::prntDay() {
    cout<<endl<<"Day "<<input<<" = "<<month<<" "<<day<<endl;
}