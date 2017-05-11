/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "AllCls.h"
#include <iostream>
#include <string>
using namespace std;

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

Staff::Staff(string n, int i, string d, string p) {
    name=n;
    idNum=i;
    dprtmnt=d;
    posishn=p;
}

Staff::Staff(string n, int i) {
    name=n;
    idNum=i;
    dprtmnt="";
    posishn="";
}

Staff::Staff() {
    name="";
    idNum=0;
    dprtmnt="";
    posishn="";
}

void Staff::setName(string n) {
    name=n;
}

void Staff::setID(int i) {
    idNum=i;
}

void Staff::setDept(string d) {
    dprtmnt=d;
}

void Staff::setPos(string p) {
    posishn=p;
}

string Staff::getName() {
    return name;
}

int Staff::getID() {
    return idNum;
}
string Staff::getDept() {
    return dprtmnt;
}

string Staff::getPos() {
    return posishn;
}

Car::Car(int yr, string m) {
    yrModel=yr;
    make=m;
    speed=0;
}

void Car::axlr8() {
    speed+=5;
    cout<<"\nAccelerating..."<<endl<<endl;
}

void Car::brake() {
    speed-=5;
    cout<<"\nBraking..."<<endl<<endl;
}

int Car::getYr() {
    return yrModel;
}

string Car::getMake() {
    return make;
}

int Car::getSpd() {
    return speed;
}

PerInfo::PerInfo() {
    name="";
    address="";
    pNum="";
    age=0;
}

void PerInfo::setInfo() {
    cout<<"\nName: ";
    getline(cin, name);
    cout<<"Age: ";
    cin>>age;
    cin.ignore(256, '\n');
    cout<<"Address: ";
    getline(cin, address);
    cout<<"Phone Number: ";
    getline(cin, pNum);
}

void PerInfo::disInfo() {
    cout<<"\nName: "<<getName()<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Address: "<<getAdd()<<endl;
    cout<<"Phone Number: "<<getNum()<<endl;
}

string PerInfo::getName() {
    return name;
}

string PerInfo::getAdd() {
    return address;
}

short PerInfo::getAge() {
    return age;
}

string PerInfo::getNum() {
    return pNum;
}

NumAry::NumAry(int s) {
    size=s;
    num = new float[size];
    cout<<endl;
    for (int i=0; i<s; i++) {
        cout<<"Input #"<<i+1<<": ";
        cin>>num[i];
    }
}

float NumAry::getNum(int n) {
    return num[n];
}
float NumAry::highest() {
    float high=num[0];
    for (int i=0; i<size; i++) {
        if (num[i]>high) high=num[i];
    }
    return high;
}
float NumAry::lowest() {
    float low=num[0];
    for (int i=0; i<size; i++) {
        if (num[i]<low) low=num[i];
    }
    return low;
}
float NumAry::average() {
    float ave=0;
    for (int i=0; i<size; i++) {
        ave+=num[i];
    }
    ave/=size;
    return ave;
}

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
