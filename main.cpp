#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class foto
{
private:
    string titolo;
    string descrizione;

public:
    foto()
    {
        titolo = "";
        descrizione = "";
    }

    void setT()
    {
        cout << "Inserisci il titolo della foto: ";
        getline(cin, titolo);
    }

    string getT()
    {
        return titolo;
    }

    void setD()
    {
        cout << "Inserisci la descrizione della foto: ";
        getline(cin, descrizione);
    }

    string getD()
    {
        return descrizione;
    }

    void stampa()
    {
        cout << "Titolo: " << titolo << "| Descrizione: " << descrizione << endl;
    }
};

int main()
{

    int nf;

    cout << "Quante foto vuoi inserire? ";
    cin >> nf;
    cin.ignore();

    foto *numF = new foto[nf];

    for (int i = 0; i < nf; i++)
    {
        cout << "Inserisci i dati della " << i + 1 << " foto: ";
        numF[i].setT();
        numF[i].setD();
    }

    ofstream album("album.txt");

        if (album.is_open())
        {
            for (int i = 0; i < nf; i++)
            {
                album << numF[i].getT() << endl;
                album << numF[i].getD() << endl;
            }

            cout << "Album salvato correttamente!. ";
            album.close();
        }
        else
        {
            cout << "Errore apertura file.";
        }

        cout << "\n|Foto inserite:|\n";

        for (int i = 0; i < nf; i++)
        {
            numF[i].stampa();
        }
        

    delete[] numF;

    return 0;
}