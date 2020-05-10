#include "Firma.h"
#include "Card.h"
#include "Cash.h"
#include "Cec.h"

int Firma::contID = 0;

Firma::Firma(string s): nume(s)
{

}

Firma::~Firma()
{
    /// de implementat
}

void Firma::addTranzactie(string tip, string data){
    if (tip != "card" and tip != "cash" and tip != "cec")
        throw "invalid\n";
    if(tip == "card")
    {
        Card* card = new Card(data);
        cin >> (*card); //citesc ce e de citit la card
        Firma::contID ++;
        id = contID;
        tranzactii[id] = card;
        cardPlata+=card;
    }
    if (tip == "cash")
    {
        Cash* cash = new Cash(data);
        cin >>(*cash);
        Firma::contID++;
        id = contID;
        tranzactii[id] = cash;
        cashPlata+=cash;
    }
    if (tip == "cec")
    {
        Cec* cec = new Cec(data);
        cin >>(*cec);
        Firma::contID++;
        id = contID;
        tranzactii[id] = cec;
        cecPlata+=cec;
    }
}
void Firma::afiseazaToateTranzactiile(){

    for (auto &it: tranzactii)
    {
        cout << "id-ul tranzactiei este " << it.first<<"\n";
        it.second->printDate();
        cout <<"\n";
    }
}

Firma& Firma:: operator = (const Firma& obj)
{
    ///stergem ce e de sters din this
    for (auto &it : tranzactii)
        delete it.second;
    tranzactii.clear();
    for (auto & it : obj.tranzactii)
    {
        if (dynamic_cast<Card*>(it.second))
        {
            tranzactii[it.first] = new Card(*(dynamic_cast<Card*>(it.second)));
        }
        if (dynamic_cast<Cash*>(it.second))
        {
            tranzactii[it.first] = new Cash(*(dynamic_cast<Cash*>(it.second)));
        }
        if (dynamic_cast<Cec*>(it.second))
        {
            tranzactii[it.first] = new Cec(*(dynamic_cast<Cec*>(it.second)));
        }
    }
    cardPlata = obj.cardPlata;
    cashPlata = obj.cashPlata;
    cecPlata = obj.cecPlata;
    id = obj.id;




}

void Firma::afiseazaTranzactiiTip(string tip)
{
    if (tip != "card" and tip != "cash" and tip != "cec")
        throw "invalid\n";
    if (tip == "card")
        cardPlata.afisezaDate();
    if(tip == "cash")
        cashPlata.afisezaDate();
    if (tip == "cec")
        cecPlata.afisezaDate();

}


void Firma::afiseazaNrTranzactii()
{
    cout << Firma::contID<<"\n";
}
