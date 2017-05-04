/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on April 11, 2017, 9:20 PM
 * Purpose: Monkey Game
 * 
 * Problem: Computer will shuffle cards and give each player half of the deck.
 *      The user has option to play or not. This game requires two players. The
 *      objective of the game is to have more points than the other player by 
 *      discarding pairs in your hands. If no pairs left, next player will do
 *      the same. If no pairs left in both hands, player will anonymously choose 
 *      a card from opponent's hand and if it is a pair, 3 points are added and
 *      player's turn continues. If it's not a pair, the next player will have
 *      his or her turn. If cards are not discarded after 5 turns of each 
 *      player, game ends and score tallies. Player with highest point is the
 *      winner and the loser is called a MONKEY!
 */

//System Libraries
#include <iostream>     //Input/Output Stream
#include <fstream>      //File Stream
#include <ctime>        //Time Library
#include <cstdlib>      //C Standard Library
#include <iomanip>      //Header Library
using namespace std;

//User Libraries
#include "Array.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
Card *filDeck (int, int *, fstream &, string);      //Fill structure array
int *index (int);                           //Fill index pointer
void shuffle (int *, int);                  //Shuffle index for cards
void destroy(Card *);                       //Delete allocated memory
void shwCrd1 (Card *, char);                //Show Card of each with other player hidden
void shwCrd2 (Card *, char);                //Show Card of each with other player hidden
void shwBoth (Card *, char);                //Show cards of both players
void shwPly1 (Card *, int [], int);         //Show cards of Player 1
void shwPly2 (Card *, int [], int);         //Show cards of Player 2
bool valid8 (Card *, short, short, bool);   //Validate user input if it is a pair
bool valid82 (Card *, short, short, bool);  //Validate user input if it is a pair part 2
void srtNum (int [], int);                  //Sort temporary array
void pntSfar (int, int);                    //Points so far
void bothLft (Card *, int [], int [], bool, int);   //Both cards left after removing pairs
void ply1Lft (Card *, bool, int [], int);       //Player 1 Cards left
void ply2Lft (Card *, bool, int [], int);       //Player 2 cards left
void shwPlay (Card *, bool, int [], int [], int);       //Both Players cards left
bool check1 (int [], short, short, int);            //Check for validation
bool check2 (int [], int [], bool, short, short, int);  //Check for validation
bool finish (int [], int[], int);               //Check if all cards are discarded
void shwAll (Card *, int [], int [], int);      //Show cards for both players without hidden

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int NSIZE=80;                     //Name Size
    char player1[NSIZE], player2[NSIZE],    //Player 1 and Player 2 C-String
         start, player, discard;            //Start game, choose player, discard pairing
    int size=52, p1pnt=0, p2pnt=0,          //Size for allocation,  Player 1 points, Player 2 points
        gmPly1=0, gmPly2=0, cntr1=1,        //Game Play counter
        cntr2=1;                            //Count for array number
    int trsh1[27]={}, trsh2[27]={};         //Trash array - where discarded cards are put in
    bool x=true, y=true,                    //LOOPS: x-play game, y-choose player,
         a=true, b=true, c=true,            //a-card elimination, b-pair discard, c-turn elimination
         change=true, play=true,            //change-pair elimination, play-change player
         end=true;                          //end-end all loop for score tally
    short frst, scnd;                       //1st Card, 2nd Card
    short trn1=5, trn2=5;                   //Remaining turns
    int *stand=index(size);                 //Database Array Sort
    shuffle(stand, size);                   //Shuffle index
    
    cout<<"\t\tWelcome to the Monkey Game!"<<endl<<endl;
    cout<<"Mechanics: There are two players in the game and the cards are\n"
        <<"evenly divided between the two. If a player has the same value\n"
        <<"in one hand, the two card goes into the bin. The goal is to be\n"            //Explain rules
        <<"the first to lose all the cards. When there are no more of the\n"
        <<"the pair, each player gets to pick one card from the opponent.\n"
        <<"Do this until one player wins. Loser is called the MONKEY!"<<endl<<endl;
    
    do {
        cout<<"Would you like to play the game?"<<endl;             //Prompt user for game play
        cout<<"     Y - Yes | N - No"<<endl;
        cout<<"\nCHOICE: ";
        cin>>start;
        if (start=='y'||start=='Y') x=false;                        //If they chose to play, get to next loop
        else if (start=='n'||start=='N') {                          //If 'n', delete index pointer, end game
            delete []stand;             
            return 0;
        }
        else cout<<"\nYou can only choose Y or N!"<<endl<<endl;     //Invalidate if input isn't 'Y' or 'N'
    } while(x);             //Continue loop if x remains true
    
    do {
        cout<<"\n             PLAY GAME AS:"<<endl<<endl;
        cout<<"     1 - Player 1 | 2 - Player 2"<<endl;             //Prompt user to choose player
        cout<<"              Q - QUIT"<<endl;
        cout<<"\nCHOICE: ";
        cin>>player;
        if (player=='1') {                          //If they chose 1, become player 1
            play=true;                              //Exit loop
            y=false;
        }
        else if (player=='2') {                     //If they chose 2, become player 2
            play=false;                             //Exit loop
            y=false;
        }
        else if (player=='Q'||player=='q') {        //If they chose 'Q', delete index. end game
            delete []stand;
            return 0;
        }            
        else cout<<"\nYou can only choose 1, 2 or Q!"<<endl<<endl;      //Invalidate if input '1', '2', or 'Q'
    } while(y);             //Continue loop if y remains true
    
    cin.ignore(256, '\n');
    cout<<"\nPlayer 1 (Name): ";            //Prompt user for name (player 1 & 2)
    cin.getline(player1, NSIZE);
    cout<<"Player 2 (Name): ";              
    cin.getline(player2, NSIZE);
    
    fstream in;                                         //Filestream in
    Card *deck=filDeck(size, stand, in, "deck.txt");    //Fill deck from cards in file
    cout<<"\nCards have been dispersed!"<<endl;
 
    shwBoth(deck, player);          //Show player his/her card
    
    cout<<"Press ENTER to start game!"<<endl;
    cin.get();
    
    //Process by mapping inputs to outputs
    do {                //Start first part of the game - loop hand card elimination
        if (gmPly1==1&&gmPly2==1) change=false;             //If each player had their turn, exit elimination loop
        else {
            if (play) {                                     //If player 1, show player 1 deck
                cout<<"\nPLAYER 1's Turn"<<endl<<endl; 
                shwPly1(deck, trsh1, 27);
            }
            else {
                cout<<"\nPlayer 2's Turn"<<endl<<endl;      //If Player 2, show player 2 deck
                shwPly2(deck, trsh2, 27);
            }
            do {                                            //Start elimination loop
                cout<<"Note: To quit entire game, input the same number for 1st card & 2nd card."<<endl;
                cout<<"If there's no more pair available, input '0' in both cards. To eliminate"<<endl;     //Explain rules
                cout<<"pairs in your hand, put in the corresponding number of your card. If the"<<endl;
                cout<<"input cards are not a pair, you get a point deduction. Otherwise, if the"<<endl;
                cout<<"cards are a pair, you get 2 points!"<<endl<<endl;
                cout<<"Put in the corresponding number of your cards!"<<endl<<endl;
                cout<<"1st Card: ";
                cin>>frst;                      //Prompt user for first card
                cout<<"2nd Card: ";
                cin>>scnd;                      //Prompt user for second card
                if (frst<0||frst>26||scnd<0||scnd>26) {             //If any input is less than 0 or greater than 26, invalidate!
                    cout<<"\nNumber unidentified!"<<endl<<endl;
                    if (play) shwPly1(deck, trsh1, 27);
                    else shwPly2(deck, trsh2, 27);
                }
                else {
                    if (frst==0&&scnd==0) {             //If user put '0' in both card, exit elimination loop
                        if (play) {
                            gmPly1++;                   //If player 1, change to player 2
                            play=false;                 //Add game play counter
                        }
                        else {
                            gmPly2++;                   //If player 2, change to player 1
                            play=true;                  //Add game play counter
                        }
                        a=false;                        //Set a to false
                    }
                    else if (frst==scnd) {              //If input is the same except 0, quit game play
                        destroy(deck);                  //Delete deck and index
                        delete []stand;
                        return 0;
                    }
                    else {                              //If input is none other than above, check player
                        if (play) {                     //If player 1
                            if (check1(trsh1, frst, scnd, 27)) {    //Check if input has already been used
                                if (valid8(deck, frst, scnd, play)) {   //If not, validate if cards are a pair
                                    trsh1[cntr1]=frst; cntr1++;         //If cards are a pair, add to trash array
                                    trsh1[cntr1]=scnd; cntr1++;
                                    cout<<"\nYou got it!"<<endl;
                                    p1pnt+=2;                           //Add two points for player
                                    shwPly1(deck, trsh1, 27);           //Show Player Cards
                                }
                                else {
                                    cout<<"\nIt's not a pair!"<<endl;       //If cards are not a pair
                                    cout<<"1 point is deducted to your score!"<<endl<<endl;     //Deduct 1 point
                                    p1pnt--;
                                }
                            }
                            else {                //If input has already been used
                                cout<<"\nNumber unidentified!"<<endl<<endl;     //Invalidate and show player cards
                                shwPly1(deck, trsh1, 27);
                            }
                        }
                        else {                                              //Do the same if player is player 2
                            if (check1(trsh2, frst, scnd, 27)) {
                                if (valid8(deck, frst, scnd, play)) {
                                    trsh2[cntr2]=frst; cntr2++;
                                    trsh2[cntr2]=scnd; cntr2++;
                                    cout<<"\nYou got it!"<<endl;
                                    p2pnt+=2;
                                    shwPly2(deck, trsh2, 27);
                                }
                                else {
                                    cout<<"\nIt's not a pair!"<<endl;
                                    cout<<"1 point is deducted to your score!"<<endl<<endl;
                                    p2pnt--;
                                }
                            }
                            else {
                                cout<<"\nNumber unidentified!"<<endl<<endl;
                                shwPly2(deck, trsh2, 27);
                            }
                        }
                    }
                }
            } while(a);     //Continue loop if a remains true
        }
    } while(change);        //Continue loop if change remains true
    
    pntSfar(p1pnt, p2pnt);  //Show Score board
    do {
        if (trn1==0&&trn2==0) end=false;        //If no turns left, end game loop
        else {
            if (play) {                         //If player is player 1
                cout<<"Player 1's Turn"<<endl<<endl;    //Show cards deck
                shwPlay(deck, play, trsh1, trsh2, 27);
            }
            else {
                cout<<"Player 2's Turn"<<endl<<endl;    //If player is player 2
                shwPlay(deck, play, trsh1, trsh2, 27);  //Show cards deck
            }
            do {                      //Ask if user wants to discard a pair in hand
                cout<<"\nWould you like to discard a pair in your hand?"<<endl;
                cout<<"             Y - Yes | N - No                 "<<endl;
                cout<<"CHOICE: ";
                cin>>discard;
                if (discard=='Y'||discard=='y') {       //If yes, prompt entering the two cards
                    cout<<"\nInput corresponding number."<<endl<<endl;
                    cout<<"1st Card: ";
                    cin>>frst;
                    cout<<"2nd Card: ";
                    cin>>scnd;
                    if (play) {     //If player 1, check if input number is within hand
                        if (check1(trsh1, frst, scnd, 27)) {
                            if (valid8(deck, frst, scnd, play)) {   //If it is, validate if both cards are a pair
                                trsh1[cntr1]=frst; cntr1++;         //If yes, add cards to trash array
                                trsh1[cntr1]=scnd; cntr1++;
                                cout<<"\nYou got it!"<<endl;
                                p1pnt++;                            //Add only 1 point for pairing
                                ply1Lft(deck, play, trsh1, 27);     //Show cards left
                            }
                            else {                                  //If invalid, deduct 1 point to score
                                cout<<"\nIt's not a pair!"<<endl;
                                cout<<"1 point is deducted to your score!"<<endl<<endl;
                                p1pnt--;
                            }
                        }
                        else {
                            cout<<"\nNumber unidentified!"<<endl<<endl;//If input number is not within hand,
                            ply1Lft(deck, play, trsh1, 27);            //invalidate. show cards left
                        }
                    }
                    else {          //If player 2, do the same
                        if (check1(trsh2, frst, scnd, 27)) {
                            if (valid8(deck, frst, scnd, play)) {
                                trsh2[cntr2]=frst; cntr2++;
                                trsh2[cntr2]=scnd; cntr2++;
                                cout<<"\nYou got it!"<<endl;
                                p2pnt++;
                                ply2Lft(deck, play, trsh2, 27);
                            }
                            else {
                                cout<<"\nIt's not a pair!"<<endl;
                                cout<<"1 point is deducted to your score!"<<endl<<endl;
                                p2pnt--;
                            }
                        }
                        else {
                            cout<<"\nNumber unidentified!"<<endl<<endl;
                            ply2Lft(deck, play, trsh2, 27);
                        }
                    }
                }
                else if (discard=='N'||discard=='n') {      //If no, exit discarding loop
                    b=false;
                }
                else cout<<"\nYou can only choose Y or N!"<<endl<<endl;
            } while (b);
            c=true;     //Declare c as true
            do {
                if (finish(trsh1, trsh2, 27)) {     //If no more cards left, exit all loop
                    end=false;
                    c=false;
                }
                else {
                    shwPlay(deck, play, trsh1, trsh2, 27);      //If cards still exist, show cards
                    cout<<"\nNote: Try to eliminate card in your hands as you pick one card"<<endl;
                    cout<<"  from your opponent. If it's a pair, you get 3 points, and you"<<endl;      //Explain rules for 2nd part
                    cout<<"  still get another turn. No deductions if your wrong. If cards"<<endl;
                    cout<<"  are not discarded in 5 turns, game ends and score tallies!"<<endl<<endl;
                    cout<<"Reminder: Input '0' in both cards to quit!"<<endl<<endl;
                    if (play) cout<<"Turns Left: "<<trn1;   //Show turns left based on player
                    else cout<<"Turns Left: "<<trn2;
                    cout<<"\n\nYour Card: ";
                    cin>>frst;                  //Prompt user to input card number from hand
                    cout<<"Opponent's Card: ";
                    cin>>scnd;                  //Prompt user to input number from opponent's hand
                    if (frst==0&&scnd==0) {     //If player chose to quit, end game straight to tally
                        c=false;
                        end=false;
                    }
                    else {
                        if (play) {         //If player 1, check if input is in both hands
                            if (check2(trsh1, trsh2, play, frst, scnd, 27)) {
                                if (valid82(deck, frst, scnd, play)) {      //If yes, validate if it is a pair
                                    trsh1[cntr1]=frst; cntr1++;             //If it is, add both to trash bin
                                    trsh2[cntr2]=scnd; cntr2++;             //Add 3 points to player
                                    cout<<"\nYou got it!"<<endl;
                                    p1pnt+=3;                               //Continue game
                                }
                                else {                                      
                                    cout<<"\nIt's not a pair!"<<endl<<endl; //If not a pair, change player
                                    trn1--;                                 //Exit inner loop
                                    play=false;                             //Deduct a turn from player 1                                    
                                    c=false;
                                }
                            }
                            else cout<<"\nNumber unidentified!"<<endl<<endl;    //If input is unidentified, notify user

                        }
                        else {                  //If player 2, do the same with player 1
                            if (check2(trsh1, trsh2, play, frst, scnd, 27)) {
                                if (valid82(deck, frst, scnd, play)) {
                                    trsh2[cntr2]=frst; cntr2++;
                                    trsh1[cntr1]=scnd; cntr1++;
                                    cout<<"\nYou got it!"<<endl;
                                    p2pnt+=3;
                                }
                                else {
                                    cout<<"\nIt's not a pair!"<<endl<<endl;
                                    trn2--;
                                    play=true;
                                    c=false;
                                }
                            }
                            else cout<<"\nNumber unidentified!"<<endl<<endl;
                        }
                    }
                }
            } while(c); //Continue loop if c remains true
        }
    } while (end);      //Continue loop if end remains true
    
    if (trn1==0&&trn2==0) shwAll(deck, trsh1, trsh2, 27);
    pntSfar(p1pnt, p2pnt);      //Show score board after game
    
    fstream out;        //File stream out
    out.open("Records.txt", ios::out | ios::app);   //Write results to a file
    
    //Output values
    if (p1pnt>p2pnt) {                          //If player 1 has highest point, declare player 1 winner with
        cout<<"\t\t"<<player1<<" WINS!"<<endl<<endl;    //name embedded
        cout<<"Data recorded to a file."<<endl;
        out<<player1<<" WINS!"<<endl<<endl;
        out<<player1<<" - "<<p1pnt<<" points"<<endl;
        out<<player2<<" - "<<p2pnt<<" points"<<endl<<endl;
    }
    else if (p1pnt<p2pnt) {                     //If player 2 has highest point, declare player 2 winner with
        cout<<"\t\t"<<player2<<" WINS!"<<endl<<endl;    //Name embedded
        cout<<"Data recorded to a file."<<endl;
        out<<player2<<" WINS!"<<endl<<endl;
        out<<player2<<" - "<<p2pnt<<" points"<<endl;
        out<<player1<<" - "<<p1pnt<<" points"<<endl<<endl;
    }
    else {
        cout<<"\t\t"<<"IT'S A TIE!"<<endl<<endl;        //Announce if it's a tie
        cout<<"Data recorded to a file."<<endl;
        out<<"IT'S A TIE!"<<endl<<endl; 
        out<<player1<<" - "<<p1pnt<<" points"<<endl;        //Write every result to a file
        out<<player2<<" - "<<p2pnt<<" points"<<endl<<endl;
    }
    out.close();
    
    destroy(deck);      //Delete structure array
    delete []stand;     //Delete index array
	
    return 0;
}

Card *filDeck(int s, int *ind, fstream &in, string file) {
    //Input Values
    Card *d=new Card[s];
    d->cards=new string[s];
    d->p1=new string[27];
    d->p2=new string[27];
    
    in.open(file, ios::in);
    for (int i=0; i<s; i++) {
        in>>d->cards[i];
    }    
    in.close();
    
    for (int i=0, c=1; c<27&&i<26; i++, c++) { 
        if (c==0) d->p1[0]=="J";
        else d->p1[c]=d->cards[ind[i]];
    }   
    for (int i=26, c=1; c<27&&i<s; i++, c++) {    
        if (c==0) d->p2[0]=="J";
        else d->p2[c]=d->cards[ind[i]];
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

void shwCrd1 (Card *d, char p) {
    cout<<endl<<"PLAYER 1: ";
    if (p=='2') {
        for (int i=1; i<27; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
    else {
        for (int i=1; i<27; i++) {
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
        for (int i=1; i<27; i++) {
            cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            cout<<setw(3)<<i;
        }
    }
    else {
        for (int i=1; i<27; i++) {
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

void shwPly1 (Card *d, int t[], int s) {
    int copy[27]={};
    for (int c=1; c<s; c++) {
        copy[c]=t[c];
    }
    srtNum(copy, s);
    cout<<endl<<"PLAYER 1: ";
    for (int i=1; i<s; i++) {
        for (int c=1; c<s; c++) {
            if (copy[c]==i) {
                cout<<" 0 ";
                i++;
            }
        }
        if (i==27)i--;
        else cout<<d->p1[i]<<" ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=26; i++) {
        for (int c=1; c<s; c++) {
            if (copy[c]==i) {
                cout<<"   ";
                i++;
            }
        }
        if (i==27)i--;
        else cout<<setw(3)<<i;
    }
    cout<<endl<<endl;
}

void shwPly2 (Card *d, int t[], int s) {
    int copy[27]={};
    for (int c=1; c<s; c++) {
        copy[c]=t[c];
    }
    srtNum(copy, s);
    cout<<endl<<"PLAYER 2: ";
    for (int i=1; i<s; i++) {
        for (int c=1; c<s; c++) {
            if (copy[c]==i) {
                cout<<" 0 ";
                i++;
            }
        }
        if (i==27)i--;
        else cout<<d->p2[i]<<" ";
    }
    cout<<endl<<"         ";
    for (int i=1; i<=26; i++) {
        for (int c=1; c<s; c++) {
            if (copy[c]==i) {
                cout<<"   ";
                i++;
            }
        }
        if (i==27)i--;
        else cout<<setw(3)<<i;
    }
    cout<<endl<<endl;
}

bool valid8 (Card *d, short frst, short scnd, bool p) {
    if (p) {
        if (frst<scnd) {
            string temp1 = d->p1[frst];
            string temp2 = d->p1[scnd];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }
        else {
            string temp1 = d->p1[scnd];
            string temp2 = d->p1[frst];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }        
    }
    
    else {
        if (frst<scnd) {
            string temp1 = d->p2[frst];
            string temp2 = d->p2[scnd];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        }
        else {
            string temp1 = d->p2[scnd];
            string temp2 = d->p2[frst];
            if (temp1[0]==temp2[0]) return true;
            else return false;
        } 
    }
}

bool valid82 (Card *d, short frst, short scnd, bool p) {
    if (p) {
        string temp1 = d->p1[frst];
        string temp2 = d->p2[scnd];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
    else {
        string temp1 = d->p2[frst];
        string temp2 = d->p1[scnd];
        if (temp1[0]==temp2[0]) return true;
        else return false;
    }
}

void srtNum (int t[], int s) {
    for(int i=0;i<s-1;i++) {
        for(int j=i+1;j<s;j++){
            if(t[i]>t[j]){
                int temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
}

bool entry (short e[], short s, short num) {
    for (int i=0; i<s; i++) {
        if (e[i]==num) return false;
    }
    return true;
}

void pntSfar (int p1, int p2) {
    cout<<endl<<endl;
    cout<<"\t==================================="<<endl;
    cout<<"\t            SCORE BOARD"<<endl;
    cout<<"\t==================================="<<endl;
    cout<<"\t        PLAYER 1 ---- "<<p1<<" pts."<<endl;
    cout<<"\t        PLAYER 2 ---- "<<p2<<" pts."<<endl;
    cout<<"\t==================================="<<endl<<endl;
}

void ply1Lft (Card *d, bool p, int t[], int s) {
    int copy[27]={};
    for (int c=1; c<s; c++) {
        copy[c]=t[c];
    }
    srtNum(copy, s);
    if (p) {
        cout<<endl<<"PLAYER 1: ";
        for (int i=1; i<s; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<d->p1[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl;
    }
    else {
        cout<<endl<<"PLAYER 1: ";
        for (int i=1; i<s; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl<<endl;
    }
}

void ply2Lft (Card *d, bool p, int t[], int s) {
    int copy[27]={};
    for (int c=1; c<s; c++) {
        copy[c]=t[c];
    }
    srtNum(copy, s);
    if (p) {
        cout<<endl<<"PLAYER 2: ";
        for (int i=1; i<s; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<"**"<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27) i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl;
    }
    else {
        cout<<endl<<"PLAYER 2: ";
        for (int i=1; i<s; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<d->p2[i]<<" ";
        }
        cout<<endl<<"         ";
        for (int i=1; i<=26; i++) {
            for (int c=1; c<s; c++) {
                if (copy[c]==i) {
                    i++;
                }
            }
            if (i==27)i--;
            else cout<<setw(3)<<i;
        }
        cout<<endl;
    }
}

void shwPlay (Card *d, bool p, int t1[], int t2[], int s) {
    ply1Lft(d, p, t1, s);
    ply2Lft(d, p, t2, s);
    cout<<endl;
}

bool check1 (int t[], short frst, short scnd, int s) {
    for (int i=1; i<s; i++) {
        if (t[i]==frst) return false;
        if (t[i]==scnd) return false;
    }
    return true;
}

bool check2 (int t1[], int t2[], bool p, short frst, short scnd, int s) {
    if (p) {
        for (int c=1; c<s; c++) {
            if (t1[c]==frst) return false;
            if (t2[c]==scnd) return false;
        }
        return true;
    }
    else {
        for (int c=1; c<s; c++) {
            if (t1[c]==scnd) return false;
            if (t2[c]==frst) return false;
        }
        return true;
    }
}

bool finish (int t1[], int t2[], int s) {
    int cnt1=1, cnt2=1;
    for (int i=1; i<s; i++) {
        for (int c=1; c<s; c++) {
            if (t1[c]==i) cnt1++;
            if (t2[c]==i) cnt2++;
        }
    }
    if (cnt1==s&&cnt2==s) return true;
    else return false;
}

void name (char p[], const int NSIZE) {
    for (int i=0; i<NSIZE && p[i]!='\0'; i++) {
        cout<<p[i];
    }
}

void shwAll (Card *d, int t1[], int t2[], int s) {
    int copy1[27]={}, copy2[27]={};
    for (int c=1; c<s; c++) {
        copy1[c]=t1[c];
        copy2[c]=t2[c];
    }
    srtNum(copy1, s);
    srtNum(copy2, s);
    cout<<endl<<"PLAYER 1: ";
    for (int i=1; i<s; i++) {
        for (int c=1; c<s; c++) {
            if (copy1[c]==i) {
                i++;
            }
        }
        if (i==27)i--;
        else cout<<d->p1[i]<<" ";
    }
    cout<<endl<<"         ";
    cout<<endl<<"PLAYER 2: ";
    for (int i=1; i<s; i++) {
        for (int c=1; c<s; c++) {
            if (copy2[c]==i) {
                i++;
            }
        }
        if (i==27)i--;
        else cout<<d->p2[i]<<" ";
    }
    cout<<endl;
}