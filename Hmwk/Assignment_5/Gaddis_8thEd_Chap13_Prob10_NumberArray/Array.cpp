/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Array.h"
using namespace std;

NumAry::NumAry(int s) {
    size=s;
    num = new float[size];
    cout<<endl;
    for (int i=0; i<s; i++) {
        cout<<"Input #"<<i+1<<": ";
        cin>>num[i];
    }
}

float NumAry::getNum(int n) {
    return num[n];
}
float NumAry::highest() {
    float high=num[0];
    for (int i=0; i<size; i++) {
        if (num[i]>high) high=num[i];
    }
    return high;
}
float NumAry::lowest() {
    float low=num[0];
    for (int i=0; i<size; i++) {
        if (num[i]<low) low=num[i];
    }
    return low;
}
float NumAry::average() {
    float ave=0;
    for (int i=0; i<size; i++) {
        ave+=num[i];
    }
    ave/=size;
    return ave;
}