/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileRyt.h
 * Author: ShiennePatricia
 *
 * Created on June 1, 2017, 8:57 PM
 */

#ifndef FILERYT_H
#define FILERYT_H

#include <fstream>
#include <iostream>
#include <string>
#include "Points.h"
using namespace std;

template <class T>  //template class
class RytFile {     //Class to write data to a file
private:
    T *scores;      //pointer to scores accumulated
public:
    RytFile(short, short);          //constructor with scores from main as parameter
    ~RytFile(){delete []scores;}    //destructor for dynamic allocation
    T *scr(short, short);       //Set values for scores array
    void dataRyt(char *, char *, vector<string> &, vector<string> &);   //write data to a txt file and binary file
};

template <class T>
RytFile<T>::RytFile(short p1s, short p2s) {
    scores=scr(p1s, p2s);       //call set scores function
}

template <class T>
T *RytFile<T>::scr(short p1s, short p2s) {
    T *scrs=new T[2];
    scrs[0]=p1s;        //Input values used as parameters
    scrs[1]=p2s;
    return scrs;
}

template <class T>
void RytFile<T>::dataRyt(char *p1, char *p2, vector<string> &p1p, vector<string> &p2p) {
    fstream out;    //File stream out   
    out.open("Records.txt", ios::out | ios::app);   //Write results to a file
    fstream bin("Records.dat", ios::out | ios::app | ios::binary);      //Write results to a binary file       
    
    if (p1p.size()==1||p2p.size()==1) {         //check vector size if it completed
        if (p1p.size()>p2p.size()) {            //If player's two cards are eliminated
            cout<<"ALL CARDS ELIMINATED!"<<endl;
            cout<<endl<<p2<<" WINS!"<<endl;         //Player 2 is declared a winner
            cout<<p1<<" is the MONKEY!"<<endl;
            cout<<p2<<" score: "<<scores[1]<<endl;
            cout<<p1<<" score: "<<scores[0]<<endl;
            out<<"ALL CARDS ELIMINATED!"<<endl<<endl;
            out<<p2<<" WINS!"<<endl;                    //Write files in txt file
            out<<p1<<" is the MONKEY!"<<endl;
            out<<p2<<" score: "<<scores[1]<<endl;
            out<<p1<<" score: "<<scores[0]<<endl;
            bin.write(p2, sizeof(p2));                  //Write winner's name and score in binary file
            bin.write(reinterpret_cast<char *>(&scores[1]), sizeof(scores[1]));
        }
        else {
            cout<<"ALL CARDS ELIMINATED!"<<endl;        //Same procedure if player 1 won
            cout<<endl<<p1<<" WINS!"<<endl;
            cout<<p2<<" is the MONKEY!"<<endl;
            cout<<p1<<" score: "<<scores[0]<<endl;
            cout<<p2<<" score: "<<scores[1]<<endl;
            out<<"ALL CARDS ELIMINATED!"<<endl<<endl;
            out<<p1<<" WINS!"<<endl;
            out<<p2<<" is the MONKEY!"<<endl;
            out<<p1<<" score: "<<scores[0]<<endl;
            out<<p2<<" score: "<<scores[1]<<endl;
            bin.write(p1, sizeof(p1));
            bin.write(reinterpret_cast<char *>(&scores[0]), sizeof(scores[0]));
        }
    }
    else {                                          //If game play ended by player's choice, tally score and determine winner by scores
        if (scores[0]>scores[1]) {
            cout<<endl<<p1<<" won!"<<endl;          //If player 1's score is greater, player 1 wins
            cout<<p2<<" lost!"<<endl;
            out<<endl<<p1<<" won!"<<endl;
            out<<p2<<" lost!"<<endl;
            out<<p1<<" score: "<<scores[0]<<endl;       //write all data to txt and binary file
            out<<p2<<" score: "<<scores[1]<<endl;            
            bin.write(p1, sizeof(p1));
            bin.write(reinterpret_cast<char *>(&scores[0]), sizeof(scores[0]));
        }
        else if (scores[1]>scores[0]) {             //If player 2's score is greater, player 2 wins
            cout<<endl<<p2<<" won!"<<endl;          
            cout<<p1<<" lost!"<<endl;
            out<<endl<<p2<<" won!"<<endl;
            out<<p1<<" lost!"<<endl;                    //write all data to txt and binary file
            out<<p2<<" score: "<<scores[1]<<endl;
            out<<p1<<" score: "<<scores[0]<<endl;            
            bin.write(p2, sizeof(p2));
            bin.write(reinterpret_cast<char *>(&scores[1]), sizeof(scores[1]));
        }
        else {
            cout<<endl<<"IT'S A TIE!"<<endl;            //If it's a tie, record both data to a bin file
            out<<endl<<"IT'S A TIE!"<<endl;
            out<<p1<<" score: "<<scores[0]<<endl;
            out<<p2<<" score: "<<scores[1]<<endl;
            bin.write(p1, sizeof(p1));
            bin.write(reinterpret_cast<char *>(&scores[0]), sizeof(scores[0]));
            bin.write(p2, sizeof(p2));
            bin.write(reinterpret_cast<char *>(&scores[1]), sizeof(scores[1]));
        }
    }
    bin.close();    
    out.close();
}

#endif /* FILERYT_H */

