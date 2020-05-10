#ifndef CASH_H
#define CASH_H
#include <bits/stdc++.h>
#include "Tranzactie.h"
using namespace std;

class Cash : public Tranzactie
{
    public:
        Cash(string = "");
        virtual ~Cash();
        friend istream& operator >> (istream&, Cash&);
        void printDate();
    protected:

    private:
};

#endif // CASH_H
