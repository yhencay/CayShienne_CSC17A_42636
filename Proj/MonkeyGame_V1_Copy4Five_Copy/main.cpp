/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 11, 2017, 9:20 PM
 * Purpose: Monkey Game
 * 
 * Problem: 
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
Card *filDeck(int, int *, fstream &, string);
int *index(int);
void shuffle(int *, int);
void destroy(Card *);
void srtAry(Card *, int);
void rwSwap1 (Card *, int);
void rwSwap2 (Card *, int);
void shwCrd1 (Card *, char);
void shwCrd2 (Card *, char);
void shwBoth (Card *, char);
void shwPly1 (Card *, int, string []);
void shwPly2 (Card *, int, string []);
void filStat (int [], int);
bool valid8 (Card *, short, short, char);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int size=52;
    char hide = 42, start, sort, player; 
    bool x=true, y=true, z=true, a=true;
    int cnt[52]={};
    short frst, scnd;
    int *stand=index(size);
    shuffle(stand, size);
    
    cout<<"\tWelcome to the Monkey Game!"<<endl<<endl;
    cout<<"Mechanics: There are two players in the game and the cards are\n"
        <<"evenly divided between the two. If a player has the same value\n"
        <<"in one hand, the two card goes into the bin. The goal is to be\n"
        <<"the first to lose all the cards. When there are no more of the\n"
        <<"the pair, each player gets to pick one card from the opponent.\n"
        <<"Do this until one player wins. Loser is called the MONKEY!"<<endl<<endl;
    
    do {
        cout<<"Would you like to play the game?"<<endl;
        cout<<"     Y - Yes | N - No"<<endl;
        cout<<"\nCHOICE: ";
        cin>>start;
        if (start=='y'||start=='Y') x=false;
        else if (start=='n'||start=='N') {
            delete []stand;
            return 0;
        }
        else cout<<"\nYou can only choose Y or N!"<<endl<<endl;
    } while(x);
    
    do {
        cout<<"             PLAY GAME AS:"<<endl<<endl;
        cout<<"     1 - Player 1 | 2 - Player 2"<<endl;
        cout<<"              Q - QUIT"<<endl;
        cout<<"\nCHOICE: ";
        cin>>player;
        if (player=='1') y=false;
        else if (player=='2') y=false;
        else if (player=='Q'||player=='q') {
            delete []stand;
            return 0;
        }            
        else cout<<"\nYou can only choose 1, 2 or Q!"<<endl<<endl;
    } while(y);
    
    fstream in;
    Card *deck=filDeck(size, stand, in, "deck.txt");
    cout<<"\nCards have been dispersed!"<<endl;
    shwBoth(deck, player);
    
    do {
        cout<<"Would you like to sort your cards?"<<endl;
        cout<<"      Y - Yes | N - No"<<endl;
        cout<<"          Q - QUIT"<<endl;
        cout<<"\nCHOICE: ";
        cin>>sort;
        if (sort=='y'||sort=='Y') {
            srtAry(deck, size);
            shwBoth(deck, player);
            z=false;
        }
        else if (sort=='n'||sort=='N') {
            cout<<"\nCards remain in its position!"<<endl;
            shwBoth(deck, player);
            z=false;
        }
        else if (sort=='q'||sort=='Q') {
            destroy(deck);
            delete []stand;
            return 0;
        }
        else cout<<"\nYou can only choose Y, N or Q!"<<endl<<endl;
    } while(z);
    
    cout<<"Press ENTER to start game!"<<endl;
    cin.ignore(256, '\n'); 
    cin.get();
    
    string trsh1[26]={};
    string trsh2[26]={};
    int cntr1=0, cntr2=0;
    
    do {
        cout<<"Note: To quit entire game, input the same number for 1st pair & 2nd pair."<<endl;
        cout<<"If there's no pair available, input '0' in any of the pair!"<<endl<<endl;
        cout<<"Put in the corresponding number of your cards!"<<endl<<endl;
        cout<<"1st Pair: ";
        cin>>frst;
        cout<<"2nd Pair: ";
        cin>>scnd;
        if (frst==0||scnd==0) {
            a=false;
        }
        else if (frst==scnd && frst!=0 && scnd!=0) {
            destroy(deck);
            delete []stand;
            return 0;
        }
        else {
            if (valid8(deck, frst, scnd, player)) {
                if (player=='1') {
                    trsh1[cntr1]=deck->p1[frst]; cntr1++;
                    trsh1[cntr1]=deck->p1[scnd]; cntr1++;
                    cout<<"\nYou got it!"<<endl;
                    shwPly1(deck, size, trsh1);
                }
                else {
                    trsh2[cntr2]=deck->p2[frst]; cntr2++;
                    trsh2[cntr2]=deck->p2[scnd]; cntr2++;
                    cout<<"\nYou got it!"<<endl;
                    shwPly2(deck, size, trsh2);
                }
            }
            else {
                cout<<"\nIt's not a pair!"<<endl<<endl;
            }
        }
    } while(a);
    
    /*
    cout<<"\n\n1st Pair: ";
    cin>>frst;
    cout<<"2nd Pair: ";
    cin>>scnd;
    string temp1 = deck->p2[frst-1];
    string temp2 = deck->p2[scnd-1];
    if (temp1[0]==temp2[0]) cout<<"\nYou got it!";*/
    
 //   if (deck->p1[0] )
    
 /*   for(int i=0; i<26; i++) {
        cout<<deck->p2[i]<<" ";
    }
    cout<<endl;*/
    
    /*
    for (int i=0; i<size; i++) {
        cout<<stand[i]<<" ";
        if (i%13==12) cout<<endl;
    }
    
    for(int i=0; i<size; i++) {
        cout<<deck->cards[stand[i]]<<" ";
        if (i%13==12) cout<<endl;
    }*/
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
    destroy(deck);
    delete []stand;
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

Card *filDeck(int s, int *ind, fstream &in, string file) {
    Card *d=new Card[s];
    d->cards=new string[s];
    d->p1=new string[26];
    d->p2=new string[26];
    
    in.open(file, ios::in);
    for (int i=0; i<s; i++) {
        in>>d->cards[i];
    }    
    in.close();
    
    for (int i=0, c=0; i<26; i++, c++) {
        d->p1[c]=d->cards[ind[i]];
    }   
    for (int i=26, c=0; i<s; i++, c++) {
        d->p2[c]=d->cards[ind[i]];
    }
    
    return d;
}

int *index(int s) {
    int *sh=new int[s];
    for (int i=0; i<s; i++) {
        sh[i]=i;
    }
    return sh;
}

void shuffle(int *ind, int s) {
    for(int shuf=1;shuf<=7;shuf++){
        for(int each=0;each<s;each++){
            int rnd=rand()%52;
            int temp=ind[each];
            ind[each]=ind[rnd];
            ind[rnd]=temp;
        }
    }
}

void destroy(Card *d) {
    delete[]d->cards;
    delete[]d->p1;
    delete[]d->p2;
    delete[]d;
}

void srtAry(Card *d, int s) {
    bool swap, swap2;          
    do {
        swap = false;   //remains false if no swapped happened in loop
        for (int c=0; c<26-1; c++) {  
            if (d->p1[c] > d->p1[c+1]) {   //compare current element to next one
                rwSwap1 (d, c);  //if true, swap whole row by calling rowSwap function
                swap = true;     //keep swap true to continue loop
            }
        }
    } while (swap);
    
    do {
        swap2 = false;   //remains false if no swapped happened in loop
        for (int c=0; c<26-1; c++) {  
            if (d->p2[c] > d->p2[c+1]) {   //compare current element to next one
                rwSwap2 (d, c);  //if true, swap whole row by calling rowSwap function
                swap2 = true;     //keep swap true to continue loop
            }
        }
    } while (swap2);
    
  /*  for(int i=0;i<s-1;i++){
        for(int c=i+1;c<s;c++){
            if(d->p1[i]>d->p1[c]){
                string temp = d->p1[i];
                d->p1[i]=d->p1[c];
                d->p1[c]=temp;
            }
        }
    }
    for(int i=0;i<s-1;i++){
        for(int c=i+1;c<s;c++){
            if(d->p2[i]>d->p2[c]){
                string temp = d->p2[i];
                d->p2[i]=d->p2[c];
                d->p2[c]=temp;
            }
        }
    }*/
}

void rwSwap1 (Card *d, int c) {
    string temp = ""; //string temp for swapping
    temp = d->p1[c];      //assign current element to temp
    d->p1[c] = d->p1[c+1];    //change current element to next element
    d->p1[c+1] = temp;    //change temp to current element that was changed
}

void rwSwap2 (Card *d, int c) {
    string temp = ""; //string temp for swapping
    temp = d->p2[c];      //assign current element to temp
    d->p2[c] = d->p2[c+1];    //change current element to next element
    d->p2[c+1] = temp;    //change temp to current element that was changed
}

void shwCrd1 (Card *d, char p) {
    cout<<endl<<"PLAYER 1: ";
    if (p=='2') {
        for (int i=0; i<26; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
    else {
        for (int i=0; i<26; i++) {
            cout<<d->p1[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
}

void shwCrd2 (Card *d, char p) {
    cout<<endl<<"PLAYER 2: ";
    if (p=='1') {
        for (int i=0; i<26; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
    else {
        for (int i=0; i<26; i++) {
            cout<<d->p2[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
}

void shwBoth (Card *d, char p) {
    shwCrd1(d, p);
    cout<<endl;
    shwCrd2(d, p);
    cout<<endl<<endl;
}

void shwPly1 (Card *d, int s, string t[]) {
    int half=s/2;
    for(int i=0; i<half; i++) {
        for (int c=0; c<half; c++) {
            if (d->p1[i]==t[c]) {
                cout<<" 0 ";
            }
        }
        cout<<d->p1[i]<<" ";
    }
}

void shwPly2 (Card *d, int s, string t[]) {
    int half=s/2;
    
    for(int i=0; i<half; i++) {
        for (int c=0; c<half; c++) {
            if (d->p2[i]==t[c]) {
                cout<<" 0 ";
            }
        }
        cout<<d->p2[i]<<" ";
    }
  //  cout<<endl<<"         ";
  //  for (int i=1; i<=26; i++) {
  //      cout<<setw(3)<<i;
  //  }
}

void filStat (int cnt[], const int SIZE) {
    for (int i=0; i<SIZE; i++) {
        cnt[i]=28;
    }
}

bool valid8 (Card *d, short frst, short scnd, char p) {
    if (p=='1') {
        string temp1 = d->p1[frst-1];
        string temp2 = d->p1[scnd-1];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
    else {
        string temp1 = d->p2[frst-1];
        string temp2 = d->p2[scnd-1];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
}