/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumCls.h
 * Author: ShiennePatricia
 *
 * Created on May 10, 2017, 8:44 AM
 */

#ifndef NUMCLS_H
#define NUMCLS_H
#include <string>
using namespace std;

class Numbers {
private:
    int number;
    static string wrdAry[20];
    string hundred;
    string thousnd;
public:
    Numbers(int);
    void prntWrd();
};

#endif /* NUMCLS_H */

