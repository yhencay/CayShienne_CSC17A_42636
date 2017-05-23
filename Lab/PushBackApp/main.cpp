/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Shienne Cay
 *
 * Created on May 22, 2017, 1:42 PM
 */

#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
   const int SIZE = 10;    // Number of elements
   int count;              // Loop counter
   bool x=true;
   char choice;
   
   // Create a SimpleVector of ints.
   SimpleVector<int> intTable(SIZE);
   
   // Create a SimpleVector of doubles.
   SimpleVector<double> doubleTable(SIZE);

   // Store values in the two SimpleVectors.
   for (count = 0; count < SIZE; count++)
   {
      intTable[count] = (count * 2);
      doubleTable[count] = (count * 2.14);
   }

   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;
   
   // Use the standard + operator on the elements.
   cout << "\nAdding 5 to each element of intTable"
        << " and doubleTable.\n";
   for (count = 0; count < SIZE; count++)
   {
      intTable[count] = intTable[count] + 5;
      doubleTable[count] = doubleTable[count] + 5.0;
   }
   
   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;
   
   // Use the standard ++ operator on the elements.
   cout << "\nIncrementing each element of intTable and"
       << " doubleTable.\n";
   for (count = 0; count < SIZE; count++)
   {
      intTable[count]++;
      doubleTable[count]++;
   }
   
   // Display the values in the SimpleVectors.
   cout << "These values are in intTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << intTable[count] << " ";
   cout << endl;
   cout << "These values are in doubleTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << doubleTable[count] << " ";
   cout << endl;
   
   int a;
   double b;
   
   do {
       cout<<"\nWould you like to use push back?"<<endl;
       cout<<"     Y - YES || N - NO"<<endl<<endl;
       cout<<"CHOICE: ";
       cin>>choice;
       switch(choice) {
           case 'Y':
           case 'y': {
               cout<<"\nNumber value to add (int): ";
               cin>>a;
               cout<<"Number value to add (double): ";
               cin>>b;
               cout<<"\nPushed Back!"<<endl<<endl;
               intTable.pBack(a);
               doubleTable.pBack(b);
               cout << "These values are in intTable:\n";
               for (count = 0; count < SIZE+1; count++)
                  cout << intTable[count] << " ";
               cout << endl;
               cout << "These values are in doubleTable:\n";
               for (count = 0; count < SIZE+1; count++)
                  cout << doubleTable[count] << " ";
               cout << endl;
               x=false;
               break;
           }; 
           case 'N':
           case 'n': {
               cout<<"\nGoodbye!"<<endl;
               x=false;
               break;
           }; 
           default: cout<<"\nYou can only choose Y or N!"<<endl<<endl;
       }
   }while(x);
   

   return 0;
}


