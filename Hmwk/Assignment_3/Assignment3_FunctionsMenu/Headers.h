
/* 
 * File:   Headers.h
 * Author: ShiennePatricia
 *
 * Created on March 29, 2017, 10:13 PM
 */

#ifndef HEADERS_H
#define HEADERS_H

struct MovData {
    string title, direct;
    short year, runtime;
};

struct MovProf {
    string title, direct;
    short year, runtime;
    float cost, profit;
};

struct SlsData {
    string name;
    float first, second, third, fourth, total, ave;
};

struct WeaStat {
    int size;
    float *total, *high, *low, *aveT;
};

struct WeStat {
    int size;
    float *total, *high, *low, *aveT;
};

struct SoccerS {
    string *name;
    short *number;
    short *points;
};

#endif /* HEADERS_H */

