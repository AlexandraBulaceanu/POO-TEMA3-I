#include "Cash.h"
#include <string>
#include <iostream>

using namespace std;

istream& operator >> (istream& in, Cash& obj)
{
    Tranzactie* p = &obj;
    in >> *p;
    return in;
}
void Cash::printDate()
{
    cout << sumaTranzactionata <<" "<<data<<"\n";

}

Cash::Cash(string s) : Tranzactie(s)
{
    //ctor
}

Cash::~Cash()
{
    //dtor
}

