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
        cout << "Inserisci i dati della foto " << i + 1 << ": " << endl;
        numF[i].setT();
        numF[i].setD();
    }

    ofstream albumS("album.txt");

    if (albumS.is_open())
    {
        for (int i = 0; i < nf; i++)
        {
            albumS << "Titolo foto " << i + 1 << ": " << numF[i].getT() << endl;
            albumS << "Descrizione foto " << i + 1 << ": " << numF[i].getD() << endl;
        }

        cout << "Album salvato correttamente!. ";
        albumS.close();
    }
    else
    {
        cout << "Errore durante la creazione/scrittura del file.";
    }

    ifstream albumL("album.txt");
    string righe;

    if (albumL.is_open())
    {
        cout << "\n|Foto inserite:|\n";
        while (getline(albumL, righe))
        {
            cout << righe << endl;
        }
        albumL.close();
    }
    else
    {
        cout << "Errore durante l'apertura del file.";
    }

    delete[] numF;

    return 0;
}
