/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmpCls.h
 * Author: ShiennePatricia
 *
 * Created on May 5, 2017, 8:40 PM
 */

#ifndef EMPCLS_H
#define EMPCLS_H

#include <string>
using namespace std;

class Staff {
private:
    string name;
    int idNum;
    string dprtmnt;
    string posishn;
public:
    Staff(string, int, string, string);
    Staff(string, int);
    Staff();
    void setName(string);
    void setID(int);
    void setDept(string);
    void setPos(string);
    string getName();
    int getID();
    string getDept();
    string getPos();
};

#endif /* EMPCLS_H */

