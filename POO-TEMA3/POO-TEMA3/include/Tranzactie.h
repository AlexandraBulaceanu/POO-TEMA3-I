#ifndef TRANZACTIE_H
#define TRANZACTIE_H
#include <string>
#include <iostream>
using namespace std;

class Tranzactie
{
    public:
        Tranzactie(string  = "");
        virtual ~Tranzactie();
        virtual void printDate();
        double getSumaTranzactionta();
        void setSumaTranzactionata();
        friend istream& operator >> (istream&, Tranzactie& );
    protected:
        double sumaTranzactionata;
        string data;
    private:


};

#endif // TRANZACTIE_H
