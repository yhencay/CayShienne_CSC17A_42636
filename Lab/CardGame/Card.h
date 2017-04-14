/* 
 * File:   Card.h
 * Author: ShiennePatricia
 * Purpose:  Card Class Specification
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        unsigned char cNumber;
    public:
        Card(unsigned char);
        char getSuit();
        char getFVal();
        char getNum();
        char getCNum();
};

#endif /* CARD_H */

