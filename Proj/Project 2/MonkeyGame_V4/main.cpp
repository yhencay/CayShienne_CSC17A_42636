/* 
 * File:   main.cpp
 * Author: Shienne Cay
 * Created on May 27, 2017, 9:20 PM
 * Purpose: Project 2
 * 
 * Problem: Computer will shuffle cards and give each player corresponding number
 *      of cards until all cards are given. has an option to choose how many 
 *      players will play the game. The objective of the game is to discard all
 *      of your hands with a pair. On the first round, player gets to discard all
 *      pairs in hands. Second round of the game is taking a card from the player 
 *      next to you to discard one in your hand with no pair. Points are still 
 *      counted the same as the first version. If no one discards a pair in hands
 *      after 5 rounds, game ends and player will be determined by points. Player
 *      with the lowest number of points is the MONKEY or player left with the
 *      JOKER if all had no cards left is the MONKEY!
 */

//System Libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

//User Libraries
#include "Players.h"
#include "Points.h"
#include "ElimRnd.h"
#include "FileRyt.h"

//Global Constants
//Such as PI, Vc, -> Math/Science values
//as well as conversions from one system of measurements
//to another

//Function Prototypes
bool check(int [], short, short, int);

//Executable code begins here! Always begins in Main
int main(int argc, char** argv) {
     //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    char name1[80], name2[80];              //Player Names
    char start, player, discard, yElim;     //Start game, choose player, discard pairing, eliminate card
    int gmPly1=0, gmPly2=0, p1scor=0,       //Game Play counter, Player Scores
        p2scor=0, cntr1=1, cntr2=1;         //Count for array number
    int trsh1[28]={}, trsh2[27]={};         //Trash array - where discarded cards are put in
    bool x=true, y=true,                    //LOOPS: x-play game, y-choose player,
         a=true, b=true, c=true,            //a-card elimination, b-pair discard, c-elimination cards from opponents
         change=true, play=true,            //change-pair elimination, play-change player
         end=true, elim=true;               //end-end all loop for score tally, elim is for eliminating leftover pair of cards in player's hands
    short frst, scnd, pick, pair;           //1st Card, 2nd Card, Pick from opponent, Your hand
  
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
        else if (start=='n'||start=='N') return 0;                  //If no, end game
        else {
            cout<<"\nYou can only choose Y or N!"<<endl<<endl;      //Invalidate if input isn't 'Y' or 'N'
            cin.clear();
        }
    } while(x);             //Continue loop if x remains true
    
    do {
        cout<<"\n             PLAY GAME AS:"<<endl<<endl;
        cout<<"     1 - Player 1 | 2 - Player 2"<<endl;             //Prompt user to choose player to play as
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
        else if (player=='Q'||player=='q') return 0;
        else {
            cout<<"\nYou can only choose 1, 2 or Q!"<<endl;      //Invalidate if input '1', '2', or 'Q'
            cin.clear();
        }
    } while(y);             //Continue loop if y remains true
    
    cin.ignore(256, '\n');
    if (play) {
        cout<<endl;
        cout<<"Player 1 Name: ";
        cin.getline(name1, 80);
        cout<<"Player 2 Name: ";            //Prompt user to enter name
        cin.getline(name2, 80);
    }
    else {
        cout<<endl;
        cout<<"Player 2 Name: ";
        cin.getline(name2, 80);
        cout<<"Player 1 Name: ";
        cin.getline(name1, 80);
    }
    
    Player plyNum(name1, name2);            //Create object of player using names as parameter
    
    cout<<"\nCards have been dispersed!"<<endl<<endl;
 
    plyNum.shwBoth();                       //Show both cards anonymously
    
    cout<<"Press ENTER to start game!"<<endl;
    cin.get();
    
    ++plyNum;                               //Use overload operator to indicate round
    cout<<"ROUND "<<plyNum.plyRndG()<<" - Discard all pairs!"<<endl;
    
    do {                //Start first part of the game - loop hand card elimination
        if (gmPly1==1&&gmPly2==1) change=false;             //If each player had their turn, exit elimination loop
        else {
            plyNum.shwCrd(play);                            //Show card of the user current playing whether Player or Player 2
            a=true;                                         //Set a true for player change
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
                if (frst<0||frst>27||scnd<0||scnd>27) {             //If any input is less than 0 or greater than 26, invalidate!
                    cout<<"\nNumber unidentified!"<<endl<<endl;
                    if (play) plyNum.shwLeft(play, trsh1);          //Show card again based on player playing
                    else plyNum.shwLeft(play, trsh2);
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
                    else if (frst==scnd) return 0;              //If input is the same except 0, quit game play
                    else {                              //If input is none other than above, check player
                        if (play) {                     //If player 1
                            if (check(trsh1, frst, scnd, 28)) {         //Check if input has already been used
                                if (plyNum.valid8(frst, scnd, play)) {  //If not, validate if cards are a pair
                                    trsh1[cntr1]=frst; cntr1++;         //If cards are a pair, add to trash array
                                    trsh1[cntr1]=scnd; cntr1++;
                                    cout<<"\nYou got it!"<<endl;
                                    p1scor+=2;                           //Add two points for player
                                    plyNum.shwLeft(play, trsh1);           //Show Player Cards
                                }
                                else {
                                    cout<<"\nIt's not a pair!"<<endl;       //If cards are not a pair
                                    cout<<"1 point is deducted to your score!"<<endl<<endl;     //Deduct 1 point
                                    p1scor--;
                                }
                            }
                            else {                                              //If input has already been used
                                cout<<"\nNumber unidentified!"<<endl<<endl;     //Invalidate and show player cards
                                plyNum.shwLeft(play, trsh1);
                            }
                        }
                        else {                                              //Do the same if player is player 2
                            if (frst==27||scnd==27) {
                                cout<<"\nNumber Unidentified!\n\n";
                                plyNum.shwLeft(play, trsh2);
                            }
                            else {
                                if (check(trsh2, frst, scnd, 27)) {
                                    if (plyNum.valid8(frst, scnd, play)) {
                                        trsh2[cntr2]=frst; cntr2++;
                                        trsh2[cntr2]=scnd; cntr2++;
                                        cout<<"\nYou got it!"<<endl;
                                        p2scor+=2;
                                        plyNum.shwLeft(play, trsh2);
                                    }
                                    else {
                                        cout<<"\nIt's not a pair!"<<endl;
                                        cout<<"1 point is deducted to your score!"<<endl<<endl;
                                        p2scor--;
                                    }
                                }
                                else {
                                    cout<<"\nNumber unidentified!"<<endl<<endl;
                                    plyNum.shwLeft(play, trsh2);
                                }
                            }                            
                        }
                    }
                }
            } while(a);     //Continue loop if a remains true
        }
    } while(change);        //Continue loop if change remains true
    
    Elimin8 secRnd(name1, name2, p1scor, p2scor);                                   
    secRnd.points();
    plyNum.setLeft(trsh1, trsh2);    
    
    vector<string> plyr1(plyNum.getLft1());
    vector<string> plyr2(plyNum.getLft2());
    plyNum.filVec(plyr1, plyr2, trsh1, trsh2);
    ++plyNum;
    cout<<"ROUND "<<plyNum.plyRndG()<<" - ELIMINATE ALL CARDS"<<endl<<endl;
    cout<<"TOSS COIN to see who goes first!"<<endl<<endl
        <<"HEADS - PLAYER 1 | TAILS - PLAYER 2"<<endl<<endl;
    cin.ignore(256, '\n');
    cout<<"Press ENTER to proceed!"<<endl<<endl;    
    cin.get();
    unsigned short coin=rand()%2+1;
    if (coin==1) {
        cout<<"HEADS! "<<plyNum.getNme1()<<" goes first!"<<endl<<endl;
        play=true;
    }
    else {
        cout<<"TAILS! "<<plyNum.getNme2()<<" goes first!"<<endl<<endl;
        play=false;
    }
    
    secRnd.shwCrds(plyr1, plyr2);
    
    cout<<endl;
    
    do {
        if (plyr1.size()==1||plyr2.size()==1) end=false;
        else {
            gmPly1=0; gmPly2=0;
            b=true;
            do { 
                if (play) cout<<endl<<plyNum.getNme1()<<"'s Turn"<<endl;
                else cout<<endl<<plyNum.getNme2()<<"'s Turn"<<endl;
                secRnd.elimCrd(plyr1, plyr2, play);
                cout<<"Would you like to discard a pair in your hand?"<<endl;
                cout<<"             Y - Yes | N - No                 "<<endl;
                cout<<"CHOICE: ";
                cin>>discard;
                if (discard=='Y'||discard=='y') {       //If yes, prompt entering the two cards
                    cout<<"\nInput corresponding number."<<endl<<endl;
                    cout<<"1st Card: ";
                    cin>>frst;
                    cout<<"2nd Card: ";
                    cin>>scnd;
                    if (frst==0&&scnd==0) return 0;
                    if (play) {                     //If player 1
                        if (frst<plyr1.size()&&frst>0&&scnd>0&&scnd<plyr1.size()) {    //Check if input has already been used
                            if (secRnd.valid8(plyr1, plyr2, frst, scnd, play)) {
                                if (frst>scnd) {
                                    plyr1.erase(plyr1.begin()+frst);
                                    plyr1.erase(plyr1.begin()+scnd);
                                }
                                else {
                                    plyr1.erase(plyr1.begin()+scnd);
                                    plyr1.erase(plyr1.begin()+frst);
                                }
                            }
                            else {
                                cout<<"\nIt's not a pair!\n\n";
                                p1scor--;
                            }
                        }
                        else {
                            cout<<"\nNumber unidentified!\n\n";
                        }
                    }
                    else {
                        if (frst<plyr2.size()&&frst>0&&scnd>0&&scnd<plyr2.size()) {    //Check if input has already been used
                            if (secRnd.valid8(plyr1, plyr2, frst, scnd, play)) {
                                if (frst>scnd) {
                                    plyr2.erase(plyr2.begin()+frst);
                                    plyr2.erase(plyr2.begin()+scnd);
                                }
                                else {
                                    plyr2.erase(plyr2.begin()+scnd);
                                    plyr2.erase(plyr2.begin()+frst);
                                }
                            }
                            else {
                                cout<<"\nIt's not a pair!\n\n";
                                p2scor--;
                            }
                        }
                        else {
                            cout<<"\nNumber unidentified!\n\n";
                        }
                    }
                }
                else if (discard=='N'||discard=='n') {
                    if (play) {
                        gmPly1++;
                        play=false;
                    }
                    else {
                        gmPly2++;
                        play=true;
                    }
                    if (gmPly1==1&&gmPly2==1) b=false;      //If no, exit discarding loop
                }
                else {
                    cout<<"\nYou can only choose Y or N!"<<endl<<endl;
                    cin.clear();
                    b=true;
                }
            }while (b);
            c=true;     //Declare c as true
            if (play) play=false;
            else play=true;
            gmPly1=0; gmPly2=0;
            do {
                if (plyr1.size()==1||plyr2.size()==1) {
                    end=false;
                    c=false;
                }
                else {
                    if (play) cout<<endl<<plyNum.getNme1()<<"'s Turn"<<endl;
                    else cout<<endl<<plyNum.getNme2()<<"'s Turn"<<endl;
                    cout<<endl;
                    secRnd.shwCrds(plyr1, plyr2);      //If cards still exist, show cards
                    cout<<"\nNote: Try to eliminate card in your hands as you pick one card from"<<endl;
                    cout<<"  your opponent. The system will show you the card you picked. Choose"<<endl
                        <<"  the pair in accordance to your cards. If there's no pair in hand, the"<<endl
                        <<"  card will be added to your hand. If there's a pair, you get 3 points."<<endl   //Explain rules for 2nd part
                        <<"  Whoever gets rid of everything in their hands will be the winner even"<<endl
                        <<"  if the other player has a higher point. The objective of the game is "<<endl
                        <<"  eliminate all cards in your hand. WATCH OUT FOR THE MONKEY JOKER (MJ)!"<<endl<<endl;      
                    cout<<"Reminder: Input '0' picking a card to quit!"<<endl<<endl;
                    cout<<"Pick a card from opponent's hand: ";
                    cin>>pick;                  //Prompt user to input card number from hand
                    while (secRnd.limit(plyr1, plyr2, play, pick)||cin.fail()) {
                        cout<<"\nInvalid Input!\n\n";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout<<"Pick a card from opponent's hand: ";
                        cin>>pick;                  //Prompt user to input card number from hand
                    }
                    if (pick==0) {     //If player chose to quit, tally score
                        c=false;
                        end=false;
                    }
                    else {
                        secRnd.picked(plyr1, plyr2, play, pick);
                        elim=true;
                        do {
                            if (play) cout<<endl<<plyNum.getNme1()<<"'s Turn"<<endl;
                            else cout<<endl<<plyNum.getNme2()<<"'s Turn"<<endl;
                            secRnd.elimCrd(plyr1, plyr2, play);                 //Prompt user to input number from opponent's hand
                            cout<<"Is there a pair? Y - YES || N - NO "<<endl<<endl<<"CHOICE: ";
                            cin>>yElim;
                            cout<<endl;
                            if (yElim=='Y'||yElim=='y') {
                                cout<<"Your card: ";
                                cin>>pair;
                                if (secRnd.valid82(plyr1, plyr2, pick, pair, play)) {
                                    if (play) {
                                        plyr2.erase(plyr2.begin()+pick);
                                        plyr1.erase(plyr1.begin()+pair);
                                        p1scor++;
                                        play=false;
                                    }
                                    else {
                                        plyr1.erase(plyr1.begin()+pick);
                                        plyr2.erase(plyr2.begin()+pair);
                                        p2scor++;
                                        play=true;
                                    }
                                    cout<<"\nYou got it!"<<endl<<endl;
                                    elim=false;
                                }
                                else {
                                    cout<<"\nIt's not a pair!\n\n";
                                    if (play) p1scor--;
                                    else p2scor--;
                                }
                             }
                            else if (yElim=='n'||yElim=='N') {
                                bool rmze=true;
                                short pos;
                                if (play) {
                                    do {
                                        cout<<"Position to add card?\n\nCHOICE: ";
                                        cin>>pos;
                                        if (pos<plyr1.size()&&pos>0) rmze=false;
                                        else {
                                            cout<<"\nPosition must be between 0 and "<<plyr1.size()<<"!"<<endl<<endl;
                                            cin.clear();
                                        }
                                    }while(rmze);
                                    auto it=plyr1.insert(plyr1.begin()+pos, plyr2[pick]);
                                    plyr2.erase(plyr2.begin()+pick);
                                    play=false;
                                    elim=false;
                                    if (play) gmPly1++;
                                    else gmPly2++;
                                    if (gmPly1==1&&gmPly2==1) c=false;
                                }
                                else {
                                    do {
                                        cout<<"Position to add card?\n\nCHOICE: ";
                                        cin>>pos;
                                        if (pos<plyr2.size()&&pos>0) rmze=false;
                                        else {
                                            cout<<"\nPosition must be between 0 and "<<plyr2.size()<<"!"<<endl<<endl;
                                            cin.clear();
                                        }
                                    }while(rmze);
                                    auto it=plyr2.insert(plyr2.begin()+pos, plyr1[pick]);
                                    plyr1.erase(plyr1.begin()+pick);
                                    play=true;
                                    elim=false;
                                    if (play) gmPly1++;
                                    else gmPly2++;
                                    if (gmPly1==1&&gmPly2==1) c=false;
                                }
                            }
                            else {
                                cout<<"\nYou can only choose 'Y' or 'N'\n\n";
                                cin.clear();
                                elim=true;
                            }
                        }while (elim);
                    }
                }
            } while(c); //Continue loop if c remains true
        }
    }while (end);
    
    secRnd.setScr(p1scor, p2scor);
    secRnd.points();
    
    RytFile<short> data(p1scor, p2scor);
    data.dataRyt(name1, name2, plyr1, plyr2);
    
    cout<<"\nAll data written to a file!"<<endl<<endl;
    cout<<"Thank you for playing!"<<endl;
    
    //Input Values
    
    //Process by mapping inputs to outputs
    
    //Output values
        
    //Exit stage right! - This is the 'return 0' call
	
    return 0;
}

bool check(int t[], short one, short two, int s) {
    for (int i=1; i<s; i++) {
        if (t[i]==one) return false;
        if (t[i]==two) return false;
    }
    return true;
}
