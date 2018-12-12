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
        unsigned int liczbaZnakow = wiersz.size();
        fstream plikWyjsciowy;
        plikWyjsciowy.open("b.txt", ios::out);
        for(unsigned int i = liczbaZnakow; i > 0; i--)
        {
            plikWyjsciowy << wiersz.at(i-1);
        }
        plikWyjsciowy.close();
    } else cout << "Dostep do pliku zostal zabroniony lub plik nie istnieje!" << endl;

    return 0;
}
