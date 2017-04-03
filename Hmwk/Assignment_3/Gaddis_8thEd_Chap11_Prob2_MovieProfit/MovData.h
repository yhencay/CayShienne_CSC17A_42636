/* 
 * Author: Shienne Cay
 * Created on March 21, 2017, 12:49 PM
 * Purpose: Data for Movie
 *
 * Problem: Modify the Movie Data program written for Programming Challenge 1 to 
 *      include two additional members that hold the movie’s production costs 
 *      and first-year revenues. Modify the function that displays the movie 
 *      data to display the title, director, release year, running time, and 
 *      first year’s profit or loss. 
 */

#ifndef MOVDATA_H
#define MOVDATA_H

struct MovData {
  //  int size;
    string title, direct;
    short year, runtime;
    float cost, profit;
};

#endif /* MOVDATA_H */

