/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Players.h
 * Author: ShiennePatricia
 *
 * Created on May 27, 2017, 12:26 PM
 */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "Cards.h"
#include <vector>
using namespace std;

class Player {
private:
    const int SIZE=53;
    const int CSIZE=28;
    short plyRnd, userPly;    
    short numLft1, numLft2;
    int *random;
    Card *deck;
protected:
    char p1name[80], p2name[80];
public:
    Player();
    ~Player();
    void filVec(vector<string> &, vector<string> &, int [], int []);
    void shwBoth();
    virtual void points();
    void setDeck(int *);
    void setPly1();
    void setPly2();
    void setLeft(int [], int []);
    short getLft1();
    short getLft2();
    string getNme1();
    string getNme2();
    void shwCrd(bool);
    void srtCopy(int [], int);
    virtual bool valid8(short, short, bool);
    void shwLeft(bool, int []);
    const int getSIZE();
    const short gtCSIZE();
    int *getRndm();
    Card *filDeck(int *);
    int *indxAry();
    void operator ++();
};

#endif /* PLAYERS_H */

