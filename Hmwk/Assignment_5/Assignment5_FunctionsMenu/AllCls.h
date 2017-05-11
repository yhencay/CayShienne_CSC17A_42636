/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AllCls.h
 * Author: ShiennePatricia
 *
 * Created on May 10, 2017, 10:26 PM
 */

#ifndef ALLCLS_H
#define ALLCLS_H

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

class Car {
private:
    int yrModel;
    string make;
    int speed;
public:
    Car(int, string);
    void axlr8();
    void brake();
    int getYr();
    string getMake();
    int getSpd();
};

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

class NumAry {
private:
    float *num;
    int size;
public:
    NumAry(int);
    ~NumAry(){delete []num;};
    float getNum(int);
    float highest();
    float lowest();
    float average();
};

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

class YrMonth {
private:
    int day;
public:
    YrMonth(string, int);
};

#endif /* ALLCLS_H */

