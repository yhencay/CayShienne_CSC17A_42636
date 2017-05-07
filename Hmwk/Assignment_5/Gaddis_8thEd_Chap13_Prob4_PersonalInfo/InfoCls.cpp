/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "InfoCls.h"
using namespace std;

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
