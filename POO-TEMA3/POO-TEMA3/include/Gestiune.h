#ifndef GESTIUNE_H
#define GESTIUNE_H
#include <bits/stdc++.h>
#include "Card.h"
#include "Cec.h"
#include "Cash.h"
using namespace std;

template <class T>
class Gestiune
{
    public:
        Gestiune<T>();
        virtual ~Gestiune<T>();
        Gestiune<T> & operator +=(T*&);//supraincaracre +=
        Gestiune<T>(const Gestiune<T>& obj)
        {
            for (auto &it: obj.tranzactii)
            {
                tranzactii.push_back(new T(*it));
            }
            nrClienti = obj.nrClienti;
        }
        Gestiune<T>& operator = (const Gestiune<T>& obj)
        {

            for (auto& it: tranzactii)
                delete it;
            tranzactii.clear();
            for (auto& it: obj.tranzactii)
            {
                tranzactii.push_back(new T(*it));
            }
            nrClienti = obj.nrClienti;

        }
        void afisezaDate()
        {
            cout << "Numarul de clienti "<<getClienti()<<"\n";
            double ans = 0;
            for (auto& it : tranzactii)
                ans += it->getSumaTranzactionta();
            cout <<"Suma totala tranzactionata este "<<ans<<"\n";
            cout << getClienti()<<"\n";
            for (auto &it: tranzactii)
                it->printDate();
        }

        const int& getClienti() const
        {
            return nrClienti;
        }


    protected:

    private:
        vector <T*> tranzactii;//structura de obiecte de tipul platii
        int nrClienti;

};

template <class T>
Gestiune<T>::~Gestiune()
{
    for (auto& it: tranzactii)
        delete it;
    tranzactii.clear();
}

template<class T>
Gestiune<T>::Gestiune() : nrClienti(0)
{

}
template <class T>
Gestiune<T>& Gestiune<T>::operator += (T*& plata)
{
    nrClienti ++ ;
    T* ptr = new T(*plata);
    tranzactii.push_back(ptr);
    return *this;
}

template <>
class Gestiune <Card> {

    public:

        Gestiune()
        {
            nrClienti = 0;
        }
        virtual ~Gestiune()
        {
            for (auto& it: tranzactii)
                delete it;
            tranzactii.clear();

        }

        Gestiune<Card>& operator = (const Gestiune<Card>& obj)
        {
            numeClienti.clear();
            for (auto &it: obj.numeClienti)
                numeClienti.insert(it);

            for (auto& it: tranzactii)
                delete it;
            tranzactii.clear();
            for (auto& it: obj.tranzactii)
            {
                tranzactii.push_back(new Card(*it));
            }
            nrClienti = obj.nrClienti;
            return (*this);
        }

        Gestiune<Card>(const Gestiune<Card>& obj)
        {
            //numeClienti.clear();
            for (auto &it: obj.numeClienti)
                numeClienti.insert(it);
            for (auto &it: obj.tranzactii)
            {
                tranzactii.push_back(new Card(*it));
            }
            nrClienti = obj.nrClienti;

        }

        Gestiune<Card> & operator +=(Card*& plata)
        {
            nrClienti ++ ;
            Card* ptr = new Card(*plata);
            tranzactii.push_back(ptr);
            numeClienti.insert(plata->getNumeClient());
            nrClienti = numeClienti.size();
            return *this;

        }//supraincaracre +=

        void afisezaDate()
        {
            cout << "Numarul de clienti "<<getClienti()<<"\n";
            double ans = 0;
            for (auto& it : tranzactii)
                ans += it->getSumaTranzactionta();
            cout <<"Suma totala tranzactionata este "<<ans<<"\n";
            for (auto &it: tranzactii)
                it->printDate();
        }

        void afiseazaClienti()
        {
            cout <<"Numele clientilor:\n";
            for (auto& it: numeClienti)
                cout << it <<"\n";
        }
        const int& getClienti() const
        {
            return nrClienti;
        }

    protected:

    private:
        unordered_set<string> numeClienti;
        vector <Card*> tranzactii;//structura de obiecte de tipul platii

        int nrClienti;

};

#endif // GESTIUNE_H
