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
    const int SIZE=53;          //size of a deck
    const int CSIZE=28;         //size of half a deck with joker card
    short plyRnd, userPly;      //count of rounds in the game
    short numLft1, numLft2;     //Count of cards left after elimination of pairs in hand
    int *random;                //Database sort
    Card *deck;                 //Includes Deck, Player 1, and Player 2 cards
protected:
    string p1name, p2name;      //Player 1 and 2 Name
public:
    Player();                   //Default constructor
    Player(char *, char *);     //Constructor with parameter
    ~Player();                  //Destructor for database, deck and player 
    void filVec(vector<string> &, vector<string> &, int [], int []);    //fill Vector for round 2
    void shwBoth();     //Show Both Cards for elimination
    short plyRndG();    //Get round of the game
    void setDeck(int *);    //Randomize the deck
    void setLeft(int [], int []);       //Set numberof cards left from elimination to fill in for vector of second round
    short getLft1();        //Get number of cards left for player 1
    short getLft2();        //Get number of cards left for player 2
    string getNme1();       //Get name of Player 1
    string getNme2();       //Get name of Player 2
    void shwCrd(bool);      //Show card of players depending on the player's turn
    void srtCopy(int [], int);      //Sort copied arrays for validation
    bool valid8(short, short, bool);   //Validate if 1st card and 2nd card
    void shwLeft(bool, int []);     //Show cards left after discarding pair
    Card *filDeck(int *);       //Fill the deck and player cards
    int *indxAry();         //fill random database array
    void operator ++();     //Overload operation for round game play
};

#endif /* PLAYERS_H */

