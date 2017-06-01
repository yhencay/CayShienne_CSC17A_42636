/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Players.h
 * Author: ShiennePatricia
 *
 * Created on May 27, 2017, 1:42 PM
 */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "Cards.h"
using namespace std;

class Player {
private:
    const int NSIZE, SIZE;
    const short CSIZE;
    short p1scr, p2scr, plyRnd, userPly;
    char p1name[NSIZE], p2name[NSIZE];
    int *random;
    Card *deck;
public:
    Player();
    ~Player();
    virtual void shwBoth();
    void setDeck(int *);
    void setPly1();
    void setPly2();
    void shwCrd1();
    void shwCrd2();
    const int getSIZE();
    const short gtCSIZE();
    int *getRndm();
    Card *filDeck(int *);
    int *indxAry();
    void operator ++();
};

#endif /* PLAYERS_H */

