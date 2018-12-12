#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream plikWejsciowy;
    plikWejsciowy.open("a.txt", ios::in);
    if(plikWejsciowy.good())
    {
        cout << "Plik zostal otwarty" << endl;
        string wiersz;
        getline(plikWejsciowy, wiersz);
        plikWejsciowy.close();
        if(wiersz.empty())
        {
            cout << "Plik wejsciowy jest pusty" << endl;
            return 0;
        }
        
        unsigned int liczbaZnakow = wiersz.size();
        fstream plikWyjsciowy;
        plikWyjsciowy.open("b.txt", ios::out);
        if(!plikWyjsciowy.good())
        {
            cout << "Cos poszlo nie tak, plik wyjsciowy nie zostal otwarty/utworzony" << endl;
            return 0;
        }
        
        for(unsigned int i = liczbaZnakow; i > 0; i--)
        {
            plikWyjsciowy << wiersz.at(i-1);    // metoda at() klasy string zwraca znak o podanym położeniu, tak jak operator []
        }
        plikWyjsciowy.close();
    } else cout << "Dostep do pliku zostal zabroniony lub plik nie istnieje!" << endl;

    return 0;
}
