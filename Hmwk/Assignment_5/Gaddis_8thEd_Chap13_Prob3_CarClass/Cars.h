/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cars.h
 * Author: ShiennePatricia
 *
 * Created on May 6, 2017, 2:03 PM
 */

#ifndef CARS_H
#define CARS_H

#include <string>
using namespace std;

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

#endif /* CARS_H */

