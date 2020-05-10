#include "Cec.h"
#include <string>
using namespace std;

istream& operator >> (istream& in, Cec& obj)
{
    Tranzactie* p = &obj;
    in >> *p;
    cout <<"Numele clientului:";
    in >> obj.numeClient;
    return in;
}

void Cec::printDate()
{
    cout << sumaTranzactionata <<" "<<numeClient  <<" "<<data<<"\n";

}

Cec::Cec(string s ) : Tranzactie(s)
{
    //ctor
}

Cec::~Cec()
{
    //dtor
}
