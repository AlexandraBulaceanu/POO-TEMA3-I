#ifndef CEC_H
#define CEC_H
#include <string>
#include <iostream>
#include "Tranzactie.h"
using namespace std;

class Cec : public Tranzactie
{
    public:
        Cec(string = "");
        virtual ~Cec();
        friend istream& operator >> (istream& , Cec&);
        void printDate();

    protected:

    private:
        string numeClient;
};

#endif // CEC_H
