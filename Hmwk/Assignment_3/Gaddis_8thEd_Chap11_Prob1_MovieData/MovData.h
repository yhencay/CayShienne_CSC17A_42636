/* 
 * Author: Shienne Cay
 * Created on March 21, 2017, 12:49 PM
 * Purpose:  Specification for the Array structure
 *
 * Problem: Write a program that uses a structure named MovieData to store the 
 *      following information about a movie:
 *               Title
 *               Director
 *               Year Released
 *               Running Time (in minutes)
 *      The program should create two MovieData variables, store values in their 
 *      members, and pass each one, in turn, to a function that displays the 
 *      information about the movie in a clearly formatted manner. 
 */

#ifndef MOVDATA_H
#define MOVDATA_H

struct MovData {
  //  int size;
    string title, direct;
    short year, runtime;
};

#endif /* MOVDATA_H */

