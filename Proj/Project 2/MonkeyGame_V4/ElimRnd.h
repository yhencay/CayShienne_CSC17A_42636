/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ElimRnd.h
 * Author: ShiennePatricia
 *
 * Created on May 29, 2017, 4:41 PM
 */

#ifndef ELIMRND_H
#define ELIMRND_H

//#include "Players.h"
#include "Points.h"
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Elimin8:public Pnts {     //Inherit from abstract class
private:
    short p1Scr, p2Scr;         //Score of Players
public:
    Elimin8():Pnts() {          //Default constructor
        p1Scr=0;
        p2Scr=0;
    }
    Elimin8(short p1, short p2):Pnts() {  //Constructor with parameters
        p1Scr=p1;
        p2Scr=p2;
    }
    virtual void points() {     //Overloading function from inherited class
        cout<<endl;
        cout<<"\t==================================="<<endl;
        cout<<"\t            SCORE BOARD            "<<endl;
        cout<<"\t==================================="<<endl;        //Show score
        cout<<"\t        PLAYER 1 ---- "<<p1Scr<<" pts."<<endl;
        cout<<"\t        PLAYER 2 ---- "<<p2Scr<<" pts."<<endl;
        cout<<"\t==================================="<<endl<<endl;
    }
    void setScr(short p1, short p2) {   //Update score
        p1Scr=p1;
        p2Scr=p2;
    }    
    void shwCrds(vector<string> &p1, vector<string> &p2) {      //Show cards from vector
        cout<<"PLAYER 1: ";
        for (int i=1; i<p1.size(); i++) {
            cout<<"** ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<p1.size(); i++) {
            cout<<setw(3)<<i;
        }
        cout<<endl<<endl;
        cout<<"PLAYER 2: ";
        for (int i=1; i<p2.size(); i++) {
            cout<<"** ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<p2.size(); i++) {
            cout<<setw(3)<<i;
        }
        cout<<endl;
    }
    bool limit(vector<string> &p1, vector<string> &p2, bool p, short pk) {
        if (p) {
            if (pk<0||pk>p1.size()) return true;    //Input Invalidation
            else return false;
        }
        else {
            if (pk<0||pk>p2.size()) return true;
            else return false;
        }
    }
    void elimCrd(vector<string> &p1, vector<string> &p2, bool p) {
        if (p) {
            cout<<"\nPLAYER 1: ";
            for (int i=1; i<p1.size(); i++) {
                cout<<p1[i]<<" ";               //Show cards based on player's turn
            }
            cout<<endl<<"         ";
            for (int i=1; i<p1.size(); i++) {
                cout<<setw(3)<<i;
            }
            cout<<endl<<endl;
        }
        else {
            cout<<"\nPLAYER 2: ";
            for (int i=1; i<p2.size(); i++) {
                cout<<p2[i]<<" ";
            }
            cout<<endl<<"         ";
            for (int i=1; i<p2.size(); i++) {
                cout<<setw(3)<<i;
            }
            cout<<endl<<endl;    
        }
    }
    virtual bool valid8(vector<string> &p1, vector<string> &p2, short f, short s, bool p) {
        if (p) {
            string temp1=p1[f];
            string temp2=p1[s];         //Check if both input cards are a pair
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }
        else {
            string temp1=p2[f];
            string temp2=p2[s];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }
    }
    bool valid82(vector<string> &p1, vector<string> &p2, short pd, short pr, bool p) {
        if (p) {
            string temp1=p2[pd];
            string temp2=p1[pr];
            if (temp1[0]==temp2[0]) return true;        //Check if both cards from opponent's hand and player's hands are a pair
            else return false;
        }
        else {
            string temp1=p1[pd];
            string temp2=p2[pr];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }
    }
    void picked(vector<string> &p1, vector<string> &p2, bool p, short pd) {
        if (p) cout<<"\nYou picked "<<p2[pd]<<endl;
        else cout<<"\nYou picked "<<p1[pd]<<endl;       //Check what cards was picked
    }
};

#endif /* ELIMRND_H */

