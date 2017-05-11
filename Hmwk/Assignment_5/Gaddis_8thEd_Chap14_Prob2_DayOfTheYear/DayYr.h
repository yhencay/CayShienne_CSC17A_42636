/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayYear.h
 * Author: ShiennePatricia
 *
 * Created on May 10, 2017, 3:03 PM
 */

#ifndef DAYYEAR_H
#define DAYYEAR_H

using namespace std;

class DayOfYr {
private:
    int input, day;
    string month;
public:
    DayOfYr(int);
    string getMon();
    int getDate();
    void prntDay();
};

#endif /* DAYYEAR_H */

