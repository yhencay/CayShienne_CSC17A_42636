/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: ShiennePatricia
 *
 * Created on May 10, 2017, 4:42 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDay {
private:
    float hour;
public:
    NumDay();
    void setHour(float);
    float getHour();
    float getDay();
    float operator +(float);
    float operator -(float);
    float operator ++(int);
    float operator ++();
    float operator --(int);
    float operator --();
};

#endif /* NUMDAYS_H */

