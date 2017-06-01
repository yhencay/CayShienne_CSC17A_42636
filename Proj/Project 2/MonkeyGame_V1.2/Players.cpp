/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <fstream>
#include "Cards.h"
#include "Players.h"
using namespace std;

Player::Player() {
   NSIZE=80;
   CSIZE=28;
   SIZE=53;
   p1scr=0;
   p2scr=0;
   plyRnd=0;
   *random=indxAry();
   *deck=filDeck(random);   
}

Player::~Player() {
   delete []random;
   delete []deck->cards;
   delete []deck->p1;
   delete []deck->p2;
   delete []deck;
}

const int Player::getSIZE() {
    return SIZE;
}
const short Player::gtCSIZE() {
    return CSIZE;
}

void Player::setPly1() {
    cout<<"Player 1 Name: ";
    cin.getline(p1name, NSIZE);
}

void Player::setPly2() {
    cout<<"Player 2 Name: ";
    cin.getline(p2name, NSIZE);
}

virtual void Player::shwBoth() {
    cout<<p1name<<" Cards: ";
    for (int c=1; c<CSIZE; c++) {
        for (int i=1; i<CSIZE; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=27; i++) {
            cout<<setw(3)<<i;
        }
    }
    cout<<endl<<p2name<<" Cards: ";
    for (int c=1; c<CSIZE; c++) {
        for (int i=1; i<CSIZE-1; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
}

void Player::shwCrd1() {
    cout<<p1name<<"'s Turn"<<endl<<endl;
    for (int i=1; i<CSIZE; i++) {
        cout<<deck->p1[i]<<" ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=CSIZE-1; i++) {
        cout<<setw(3)<<i;
    }
}

void Player::shwCrd2() {
    cout<<p2name<<"'s Turn"<<endl<<endl;
    for (int i=1; i<CSIZE-1; i++) {
        cout<<deck->p2[i]<<" ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=CSIZE-2; i++) {
        cout<<setw(3)<<i;
    }
}

int *Player::indxAry() {
    int *rn=new int[SIZE];
    for (int i=0; i<SIZE; i++) {
        rn[i]=i;
    }
    for(int nShuf=1;nShuf<=7;nShuf++){
        for(int each=0;each<SIZE;each++){
            int shuf=rand()%52;
            int temp=rn[each];
            rn[each]=rn[shuf];
            rn[shuf]=temp;
        }
    }
    return rn;
}

Card *Player::filDeck(int *rnd) {
    Card *d=new Card[SIZE];
    d->cards=new string[SIZE];
    d->p1=new string[CSIZE];
    d->p2=new string[27];
    
    fstream in;
    in.open("deck.txt", ios::in);
    for (int i=0; i<SIZE; i++) {
        in>>d->cards[i];
    }    
    in.close();
    
    for (int i=0, c=1; c<28&&i<CSIZE; i++, c++) { 
        if (c==0) d->p1[0]=="J";
        else d->p1[c]=d->cards[rnd[i]];
    }   
    for (int i=28, c=1; c<27&&i<SIZE; i++, c++) {    
        if (c==0) d->p2[0]=="J";
        else d->p2[c]=d->cards[rnd[i]];
    }
    
    return d;
}
int Player::getRndm() {
    return random;
}

void Player::operator ++() {
    plyRnd=+1;
}