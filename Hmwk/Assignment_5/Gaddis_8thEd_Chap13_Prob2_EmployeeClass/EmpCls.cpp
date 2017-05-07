/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EmpCls.h"

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