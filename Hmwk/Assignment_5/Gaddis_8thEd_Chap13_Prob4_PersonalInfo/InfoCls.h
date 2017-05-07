/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfoCls.h
 * Author: ShiennePatricia
 *
 * Created on May 6, 2017, 2:41 PM
 */

#ifndef INFOCLS_H
#define INFOCLS_H

using namespace std;

class PerInfo {
private:
    string name, address, pNum;
    short age;
public:
    PerInfo();
    void setInfo();
    void disInfo();
    string getName();
    string getAdd();
    short getAge();
    string getNum();
};

#endif /* INFOCLS_H */

