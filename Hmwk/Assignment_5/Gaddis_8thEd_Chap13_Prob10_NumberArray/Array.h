/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Array.h
 * Author: ShiennePatricia
 *
 * Created on May 6, 2017, 4:21 PM
 */

#ifndef ARRAY_H
#define ARRAY_H

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

#endif /* ARRAY_H */

