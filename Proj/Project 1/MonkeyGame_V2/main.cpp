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
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
Card *filDeck(int, int *, fstream &, string, fstream &, string);
int *index(int);
void shuffle(int *, int);
void destroy(Card *);
void srtAry(Card *, int);
void rwSwap1 (Card *, int);
void rwSwap2 (Card *, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int size=52; char hide = 42;
    int *stand=index(size);
    shuffle(stand, size);
    
    cout<<"\tWelcome to the Monkey Game!"<<endl<<endl;
    cout<<"Mechanics: There are two players in the game and the cards are\n"
        <<"evenly divided between the two. If a player has the same value\n"
        <<"in one hand, the two card goes into the bin. The goal is to be\n"
        <<"the first to lose all the cards. When there are no more of the\n"
        <<"the pair, each player gets to pick one card from the opponent.\n"
        <<"Do this until one player wins. Loser is called the MONKEY!"<<endl<<endl;
    
    fstream in, on;
    Card *deck=filDeck(size, stand, in, "number.txt", on, "getsuit.txt");
    
 //   srtAry(deck, size);
    
    for(int i=0; i<26; i++) {
        cout<<deck->p1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<26; i++) {
        cout<<deck->p2[i]<<" ";
    }
    
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

Card *filDeck(int s, int *ind, fstream &in, string value, fstream &on, string suit) {
    Card *d=new Card[s];
    d->value=new char[s];
    d->suit= new char[s];
    d->p1=new char[s];
    d->p2=new char[s];
        
    in.open(value, ios::in);
    for (int i=0; i<52; i++) {
        in>>d->value[i];
    }    
    in.close();
    
    on.open(suit, ios::in);
    for (int i=0; i<52; i++) {
        on>>d->suit[i];
    }
    on.close();
    
    for (int i=0, c=0; i<26; i++, c++) {
        if (c%2==1) d->p1[c]=d->suit[ind[i]];
        else d->p1[c]=d->value[ind[i]]; 
    }   
    for (int i=26, c=0; i<s; i++, c++) {
        if (c%2==1) d->p2[c]=d->suit[ind[i]]; 
        else d->p2[c]=d->value[ind[i]];
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
    delete[]d->value;
    delete[]d->suit;
    delete[]d->p1;
    delete[]d->p2;
    delete[]d;
}
/*
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
        for (int c=0; c<52-1; c++) {  
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
//}
/*
void rwSwap1 (Card *d, int c) {
    char temp; //string temp for swapping
    temp = d->p1[c];      //assign current element to temp
    d->p1[c] = d->p1[c+1];    //change current element to next element
    d->p1[c+1] = temp;    //change temp to current element that was changed
}

void rwSwap2 (Card *d, int c) {
    char temp; //string temp for swapping
    temp = d->p2[c];      //assign current element to temp
    d->p2[c] = d->p2[c+1];    //change current element to next element
    d->p2[c+1] = temp;    //change temp to current element that was changed
}*/