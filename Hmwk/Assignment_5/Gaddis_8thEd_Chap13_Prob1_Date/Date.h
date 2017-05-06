/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Shienne Cay
 *
 * Created on May 4, 2017, 11:48 AM
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;
    string wMon;
public:
    Date(int, int, int);
    void getMon();
    void prntD8();
};

#endif /* DATE_H */

