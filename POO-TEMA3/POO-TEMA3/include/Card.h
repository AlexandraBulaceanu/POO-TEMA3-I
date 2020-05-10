#ifndef CARD_H
#define CARD_H
#include "Tranzactie.h"
#include <iostream>
#include <string>
using namespace std;

class Card : public Tranzactie
{
    public:
        Card(string = "");
        virtual ~Card();
        friend istream& operator >> (istream&, Card&);
        void printDate();
        const string getNumeClient() const;


protected:

private:
    string numeClient;
    string nrCard;
};

#endif // CARD_H
