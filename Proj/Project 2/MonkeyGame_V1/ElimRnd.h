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

#include "Players.h"
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Elimin8:public Player {
private:
    short p1Scr, p2Scr;
  //  string plyNme1, plyNme2;
public:
    Elimin8(short p1, short p2) {
        p1Scr=p1;
        p2Scr=p2;
    }
    virtual void points() {
        cout<<endl<<endl;
        cout<<"\t==================================="<<endl;
        cout<<"\t            SCORE BOARD            "<<endl;
        cout<<"\t==================================="<<endl;
        cout<<"\t        PLAYER 1 ---- "<<p1Scr<<" pts."<<endl;
        cout<<"\t        PLAYER 2 ---- "<<p2Scr<<" pts."<<endl;
        cout<<"\t==================================="<<endl<<endl;
    }
    void setScr(short p1, short p2) {
        p1Scr=p1;
        p2Scr=p2;
    }    
    void shwCrds(vector<string> &p1, vector<string> &p2) {
        cout<<"PLAYER 1: ";
        for (int i=1; i<p1.size(); i++) {
            cout<<p1[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<p1.size(); i++) {
            cout<<setw(3)<<i;
        }
        cout<<endl<<endl;
        cout<<"PLAYER 2: ";
        for (int i=1; i<p2.size(); i++) {
            cout<<p2[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<p2.size(); i++) {
            cout<<setw(3)<<i;
        }
        cout<<endl;
    }
    void elimCrd(vector<string> &p1, vector<string> &p2, bool p) {
        if (p) {
            cout<<"\nPLAYER 1: ";
            for (int i=1; i<p1.size(); i++) {
                cout<<p1[i]<<" ";
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
            string temp2=p1[s];
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
            if (temp1[0]==temp2[0]) return true;
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
        if (p) cout<<"\nYou picked "<<p2[pd]<<endl<<endl;
        else cout<<"\nYou picked "<<p1[pd]<<endl<<endl;
    }
    
    void rndmze(vector<string> &p1, vector<string> &p2, bool p) {
        if (p) {
            for(int nShuf=1;nShuf<=7;nShuf++){
                for(int each=1;each<p1.size();each++){
                    int shuf=rand()%p1.size();
                    string temp=p1[each];
                    p1[each]=p1[shuf];
                    p1[shuf]=temp;
                }
            }
        }
        else {
            for(int nShuf=1;nShuf<=7;nShuf++){
                for(int each=1;each<p2.size();each++){
                    int shuf=rand()%p2.size();
                    string temp=p2[each];
                    p2[each]=p2[shuf];
                    p2[shuf]=temp;
                }
            }
        }
    }
};

#endif /* ELIMRND_H */

