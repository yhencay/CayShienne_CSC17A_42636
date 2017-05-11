/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumDays.h"
using namespace std;

NumDay::NumDay() {
    hour=0;
}

void NumDay::setHour(float h) {
    hour=h;
}

float NumDay::getHour() {
    return hour;
}

float NumDay::getDay() {
    return hour/8;
}

float NumDay::operator +(float i) {
    float temp=hour;
    temp+=i;
    return temp;
}

float NumDay::operator -(float i) {
    float temp=hour;
    temp-=i;
    return temp;
}

float NumDay::operator ++(int i) {
    float temp=hour;
    temp++;
    hour=temp;
    return hour;
}

float NumDay::operator ++() {
    float temp=hour;
    ++temp;
    hour=temp;
    return hour;
}

float NumDay::operator --(int i) {
    hour--;
    setHour(hour);
    return hour;
}

float NumDay::operator --() {
    --hour;
    setHour(hour);
    return hour;
}