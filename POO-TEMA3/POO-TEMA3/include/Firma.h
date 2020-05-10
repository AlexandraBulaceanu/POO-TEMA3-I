#ifndef FIRMA_H
#define FIRMA_H
#include <bits/stdc++.h>
#include "Tranzactie.h"
#include "Gestiune.h"
using namespace std;

class Firma
{
    public:
        Firma(string="");
        ~Firma();
        int getNume();
        void setNume(string);
        unordered_map<int, Tranzactie*> & getTranzactii();
        void addTranzactie(string = "", string = "01/01/1990");
        void afiseazaToateTranzactiile();
        ///functie statica
        Firma& operator = (const Firma&);
        void afiseazaTranzactiiTip(string = "");
        static void afiseazaNrTranzactii();

    protected:

    private:
        int id;
        static int contID;
        const string nume;
        unordered_map<int,Tranzactie*> tranzactii;
        Gestiune<Card> cardPlata;
        Gestiune<Cash> cashPlata;
        Gestiune<Cec> cecPlata;

};

#endif // FIRMA_H
