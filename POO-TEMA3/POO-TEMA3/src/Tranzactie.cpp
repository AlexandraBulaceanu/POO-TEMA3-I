#include "Tranzactie.h"
#include <string>
#include <iostream>
using namespace std;
Tranzactie::Tranzactie(string s) : data(s)
{
    //ctor
}

Tranzactie::~Tranzactie()
{
    //dtor
}

void Tranzactie::printDate()
{

cout << sumaTranzactionata << " " << data<<"\n";

}

double Tranzactie::getSumaTranzactionta()
{
    return sumaTranzactionata;
}


istream& operator >> (istream& in, Tranzactie& obj)
{
    cout << "Introduceti suma tranzactionata:";
    cin >> obj.sumaTranzactionata;
}
