/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Cars.h"

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
