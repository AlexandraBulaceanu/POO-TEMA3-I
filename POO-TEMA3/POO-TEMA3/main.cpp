#include <iostream>
#include "Firma.h"
#include <bits/stdc++.h>

using namespace std;

void dateCheck(string s)
{
    int vec[] = {0, 1, 3, 4, 6, 7, 8, 9};

    if (s.size() < 10)
        throw "invalid\n";


    for (int i = 0; i < 8; i++){
        if (!(s[vec[i]] >= '0' and s[vec[i]] <= '9'))
        {
            throw "invalid\n";
        }
    }
    if (s[2] != 47 or s[5] != 47)
        {
            throw "invalid\n";
        }
    if ( (s[0] -48) * 10 + s[1] - 48 > 31)
        {
            throw "invalid\n";
        }
    if ((s[3] - 48) * 10 + s[4] - 48 > 12)
        {
            throw "invalid\n";
        }

}

int main()
{
    string nume,data,tipTranzactie;
    cout <<"Introduceti numele firmei:";
    cin >> nume;
    int tip;
    Firma firma(nume);
    while(1)
    {

        cout<<"1 - adaugati tranzactie noua";
        cout<<"\n2 - afisati toate tranzactiile";
        cout<<"\n3 - afisati toate tranzactiile de un anumit tip";
        cout<<"\n4 - afiseaza numarul total de tranzactii";
        cout <<"\n5 - exit\n";
        cin >> tip;
        if (tip == 1)
        {
            cout <<"Introduceti data tranzactiei:";
            cin >> data;
            try{
                dateCheck(data);
            }
            catch(const char* s)
            {
                cout << s;
                continue;
            }
            cout <<"Introduceti tipul tranzactiei:";
            cin >> tipTranzactie;
            firma.addTranzactie(tipTranzactie, data);
        }
        else if(tip == 2)
        {
            firma.afiseazaToateTranzactiile();
        }
        else if(tip ==3 )
        {
            cout <<"Introduceti tipul tranzactiei:";
            cin >> tipTranzactie;
            try
            {
                firma.afiseazaTranzactiiTip(tipTranzactie);
            }
            catch(const char* s)
            {
                cout << s;
            }
        }
        else if(tip == 4)
        {
            Firma::afiseazaNrTranzactii();
        }
        else if (tip == 5)
        {
            break;
        }
        else
        {
            cout <<"Optiune invalida\n";
        }
    }


    return 0;
}
