/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <vector>
#include "Cards.h"
#include "Players.h"
using namespace std;

Player::Player() {
   numLft1=0;
   numLft2=0;
   plyRnd=0;
   random=indxAry();
   deck=filDeck(random);   
}
Player::Player(char *n1, char *n2) {
    p1name=n1;
    p2name=n2;
    numLft1=0;
    numLft2=0;
    plyRnd=0;
    random=indxAry();
    deck=filDeck(random);
}

Player::~Player() {
    delete []random;
    delete []deck->p2;
    delete []deck->p1;
    delete []deck->cards;
    delete deck;
}

const int Player::getSIZE() {
    return SIZE;
}
const short Player::gtCSIZE() {
    return CSIZE;
}
/*
void Player::setPly1() {
    cout<<"Player 1 Name: ";
    cin.getline(p1name, 80);
}

void Player::setPly2() {
    cout<<"Player 2 Name: ";
    cin.getline(p2name, 80);
}*/

short Player::getLft1() {
    return numLft1;
}

short Player::getLft2() {
    return numLft2;
}

void Player::points() {
    cout<<endl<<endl;
    cout<<"\t==================================="<<endl;
    cout<<"\t            SCORE BOARD            "<<endl;
    cout<<"\t==================================="<<endl;
    cout<<"\t        PLAYER 1 ---- 0 pts."<<endl;
    cout<<"\t        PLAYER 2 ---- 0 pts."<<endl;
    cout<<"\t==================================="<<endl<<endl;
}

void Player::shwBoth() {
    cout<<p1name<<"'s Cards"<<endl<<endl;
    cout<<"PLAYER 1: ";
    for (int i=1; i<CSIZE; i++) {
        cout<<"** ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=27; i++) {
        cout<<setw(3)<<i;
    }
    cout<<endl<<endl<<p2name<<"'s Cards"<<endl<<endl;
    cout<<"PLAYER 2: ";
    for (int i=1; i<CSIZE-1; i++) {
        cout<<"** ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=26; i++) {
        cout<<setw(3)<<i;
    }
    cout<<endl<<endl;
}

void Player::shwCrd(bool p) {
    if (p) {
        cout<<endl<<p1name<<"'s Turn"<<endl<<endl;
        cout<<"PLAYER 1: ";
        for (int i=1; i<CSIZE; i++) {
            cout<<deck->p1[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=CSIZE-1; i++) {
            cout<<setw(3)<<i;
        }
    }
    else {
        cout<<endl<<p2name<<"'s Turn"<<endl<<endl;
        cout<<"PLAYER 2: ";
        for (int i=1; i<CSIZE-1; i++) {
            cout<<deck->p2[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=CSIZE-2; i++) {
            cout<<setw(3)<<i;
        }
    }
    cout<<endl<<endl;
}

void Player::setLeft(int t1[], int t2[]) {
    short one=0, two=0;
    for (int i=1, c=1; i<CSIZE; i++, c++) {
        if (t1[i]>0) one++;
        if (c<27) {
            if (t2[c]>0) two++;
        }        
    }
    numLft1=(27-one)+1;
    numLft2=(26-two)+1;
}

void Player::shwLeft(bool p, int t[]) {
    if (p) {
        int copy[CSIZE]={};
        for (int c=1; c<CSIZE; c++) {
            copy[c]=t[c];
        }
        srtCopy(copy, CSIZE);
        cout<<endl<<"PLAYER 1: ";
        for (int i=1; i<CSIZE; i++) {
            for (int c=1; c<CSIZE; c++) {
                if (copy[c]==i) {
                    cout<<" 0 ";
                    i++;
                }
            }
            if (i==CSIZE)i--;
            else cout<<deck->p1[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=CSIZE-1; i++) {
            for (int c=1; c<CSIZE; c++) {
                if (copy[c]==i) {
                    cout<<"   ";
                    i++;
                }
            }
            if (i==CSIZE)i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl<<endl;
    }
    else {
        int copy[27]={};
        for (int c=1; c<CSIZE-1; c++) {
            copy[c]=t[c];
        }
        srtCopy(copy, 27);
        cout<<endl<<"PLAYER 2: ";
        for (int i=1; i<CSIZE-1; i++) {
            for (int c=1; c<CSIZE-1; c++) {
                if (copy[c]==i) {
                    cout<<" 0 ";
                    i++;
                }
            }
            if (i==CSIZE-1)i--;
            else cout<<deck->p2[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            for (int c=1; c<CSIZE-1; c++) {
                if (copy[c]==i) {
                    cout<<"   ";
                    i++;
                }
            }
            if (i==CSIZE-1)i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl<<endl;    
    }
}

void Player::filVec(vector<string> &p1, vector<string> &p2, int t1[], int t2[]) {
    int copy1[CSIZE]={}, copy2[CSIZE-1]={};
    short num1=1, num2=1;
    for (int c=1; c<CSIZE; c++) {
        copy1[c]=t1[c];
        if (c<CSIZE-1) copy2[c]=t2[c];
    }
    srtCopy(copy1, CSIZE);
    srtCopy(copy2, 27);
    for (int i=1; i<CSIZE; i++) {
        for (int c=1; c<CSIZE; c++) {
            if (copy1[c]==i) {
                i++;
            }
        }
        if (i==CSIZE)i--;
        else {
            p1[num1]=deck->p1[i];
            num1++;
        }
    }
    for (int i=1; i<CSIZE-1; i++) {
        for (int c=1; c<CSIZE-1; c++) {
            if (copy2[c]==i) {
                i++;
            }
        }
        if (i==CSIZE-1)i--;
        else {
            p2[num2]=deck->p2[i];
            num2++;
        }
    }
}

void Player::srtCopy(int c[], int s) {
    for(int i=0;i<s-1;i++) {
        for(int j=i+1;j<s;j++){
            if(c[i]>c[j]){
                int temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
}

bool Player::valid8(short f, short s, bool p) {
    if (p) {
        string temp1=deck->p1[f];
        string temp2=deck->p1[s];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
    else {
        string temp1=deck->p2[f];
        string temp2=deck->p2[s];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
}

int *Player::indxAry() {
    int *rn=new int[SIZE];
    for (int i=0; i<SIZE; i++) {
        rn[i]=i;
    }
    for(int nShuf=1;nShuf<=7;nShuf++){
        for(int each=0;each<SIZE;each++){
            int shuf=rand()%53;
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
    
    for (int i=0, c=1; c<CSIZE&&i<CSIZE-1; i++, c++) { 
        if (c==0) d->p1[0]=="J";
        else d->p1[c]=d->cards[rnd[i]];
    }   
    for (int i=CSIZE-1, c=1; c<CSIZE&&i<SIZE; i++, c++) {    
        if (c==0) d->p2[0]=="J";
        else d->p2[c]=d->cards[rnd[i]];
    }
    
    return d;
}

int *Player::getRndm() {
    return random;
}

string Player::getNme1() {
    return p1name;
}

string Player::getNme2() {
    return p2name;
}

void Player::operator ++() {
    plyRnd=+1;
}