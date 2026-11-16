/*
#include <iostream>
#include <string>
using namespace std;

const size_t sudoku_groesse = 9;
const size_t eingabe_groesse = 11;

bool pruefe_spalten(int sudoku[][sudoku_groesse])
{
    bool gueltig = true;

    for (int spalte = 0; spalte < 9; spalte++)
    {
        for (int zahl = 1; zahl <= 9; zahl++)
        {
            int anzahl = 0;

            for (int zeile = 0; zeile < 9; zeile++)
            {
                if (sudoku[zeile][spalte] == zahl)
                    anzahl++;
            }

            if (anzahl > 1)
            {
                cout << "Spalte " << spalte << ": Zahl " << zahl
                     << " kommt mehrfach vor." << endl;
                gueltig = false;
            }
            else if (anzahl == 0)
            {
                cout << "Spalte " << spalte << ": Zahl " << zahl
                     << " kommt nicht vor." << endl;
                gueltig = false;
            }
        }
    }

    return gueltig;
}

bool pruefe_zeilen(int sudoku[][sudoku_groesse])
{
    bool gueltig = true;

    for (int zeile = 0; zeile < 9; zeile++)
    {
        for (int zahl = 1; zahl <= 9; zahl++)
        {
            int anzahl = 0;

            for (int spalte = 0; spalte < 9; spalte++)
            {
                if (sudoku[zeile][spalte] == zahl)
                    anzahl++;
            }

            if (anzahl > 1)
            {
                cout << "Zeile " << zeile << ": Zahl " << zahl
                     << " kommt mehrfach vor." << endl;
                gueltig = false;
            }
            else if (anzahl == 0)
            {
                cout << "Zeile " << zeile << ": Zahl " << zahl
                     << " kommt nicht vor." << endl;
                gueltig = false;
            }
        }
    }

    return gueltig;
}

bool pruefe_bloecke(int sudoku[][sudoku_groesse])
{
    bool gueltig = true;

    for (int block = 0; block < 9; block++)
    {
        for (int zahl = 1; zahl <= 9; zahl++)
        {
            int anzahl = 0;

            for (int zeile = block / 3 * 3;
                 zeile <= block / 3 * 3 + 2; zeile++)
            {
                for (int spalte = block % 3 * 3;
                     spalte <= block % 3 * 3 + 2; spalte++)
                {
                    if (sudoku[zeile][spalte] == zahl)
                        anzahl++;
                }
            }

            if (anzahl > 1)
            {
                cout << "Block " << block << ": Zahl " << zahl
                     << " kommt mehrfach vor." << endl;
                gueltig = false;
            }
            else if (anzahl == 0)
            {
                cout << "Block " << block << ": Zahl " << zahl
                     << " kommt nicht vor." << endl;
                gueltig = false;
            }
        }
    }

    return gueltig;
}

  
void konvertiere(string eingabe[], int sudoku[][sudoku_groesse])
{
    int zeile = 0;

    for (int i = 0; i < 11; i++)
    {
        // Horizontale Trennlinien überspringen
        if (i == 3 || i == 7)
            continue;

        int spalte = 0;

        for (int j = 0; j < eingabe[i].length(); j++)
        {
            if (eingabe[i][j] >= '1' && eingabe[i][j] <= '9')
            {
                sudoku[zeile][spalte] = eingabe[i][j] - '0';
                spalte++;
            }
        }

        zeile++;
    }
}


int main()
{
    int sudoku[sudoku_groesse][sudoku_groesse] = { 0 };
    string eingabe[eingabe_groesse];

    cout << "Bitte geben Sie das Sudoku ein:" << endl;

    for (size_t i = 0; i < eingabe_groesse; i++)
    {
        getline(cin, eingabe[i]);
    }

    konvertiere(eingabe, sudoku);

    bool ps = pruefe_spalten(sudoku);
    bool pz = pruefe_zeilen(sudoku);
    bool pb = pruefe_bloecke(sudoku);

    if (ps && pz && pb)
        cout << "Das Sudoku ist gueltig." << endl;

    return 0;
}

*/


#include <iostream>
#include <string>
using namespace std;

int zeichenkette_suchen_rekursiv(
    string text,
    string zkette,
    size_t text_pos = 0,
    size_t text_such_pos = 0,
    size_t zkette_such_pos = 0)
{
    // Gesamte Zeichenkette gefunden
    if (zkette_such_pos == zkette.length())
    {
        return static_cast<int>(text_pos);
    }

    // Ende des Textes erreicht
    if (text_such_pos >= text.length())
    {
        return -1;
    }

    // Zeichen stimmen überein
    if (text[text_such_pos] == zkette[zkette_such_pos])
    {
        return zeichenkette_suchen_rekursiv(
            text,
            zkette,
            text_pos,
            text_such_pos + 1,
            zkette_such_pos + 1
        );
    }

    // Zeichen stimmen nicht überein
    // Suche ab der nächsten Position
    return zeichenkette_suchen_rekursiv(
        text,
        zkette,
        text_pos + 1,
        text_pos + 1,
        0
    );
}

int main()
{
    string text;
    string zkette;

    cout << "Bitte geben Sie den Text ein: ? ";
    getline(cin, text);

    cout << "Bitte geben Sie die zu suchende Zeichenkette ein: ? ";
    getline(cin, zkette);

    int position = zeichenkette_suchen_rekursiv(text, zkette);

    if (position == -1)
    {
        cout << "Die Zeichenkette '" << zkette
             << "' ist NICHT in dem Text '" << text
             << "' enthalten." << endl;
    }
    else
    {
        cout << "Die Zeichenkette '" << zkette
             << "' ist in dem Text '" << text
             << "' enthalten." << endl;

        cout << "Sie startet ab Zeichen " << position
             << " (bei Zaehlung ab 0)." << endl;
    }

    return 0;
}
