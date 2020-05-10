#include "Card.h"
#include <iostream>
using namespace std;

istream& operator >> (istream& in, Card& obj)
{
    /// citesti suma, nume client, nr card
    Tranzactie* p = &obj;
    in >> *p;
    cout <<"Numele clientului este:";
    in >> obj.numeClient;
    cout <<"Numarul cardului este:";
    in >> obj.nrCard;
    return in;
}

void Card::printDate()
{
    cout << sumaTranzactionata <<" "<<numeClient << " " << nrCard <<" "<<data<<"\n";

}

Card::Card(string s) : Tranzactie(s)
{
    //ctor
}

Card::~Card()
{
    //dtor
}

const string Card::getNumeClient() const{
            return numeClient;
}
