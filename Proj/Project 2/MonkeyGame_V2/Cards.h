/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: ShiennePatricia
 *
 * Created on May 27, 2017, 12:23 PM
 */

#ifndef CARDS_H
#define CARDS_H

#include <string>
using namespace std;

struct Card {
    string *cards;   //53 Cards including the Joker
    string *p1;      //Player 1 distributed cards
    string *p2;      //Player 2 distributed cards
};

#endif /* CARDS_H */

