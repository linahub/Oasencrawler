#include <iostream>  // Ein-/Ausgabe
#include "charakter.h"
#include "spielfeld.h"
#include <limits>
#include <time.h>
#include <stdlib.h>
#include <stdexcept> // Exceptions

using namespace std;

int main()
{
    bool lebendig = true;
    charakter* spieler = new charakter(); // Charakter erzeugen
    spielfeld* spiel = new spielfeld(); // Spielfeld erzeugen
    while(true)
    {
        spiel->showField(*spieler); // Ausgabe von Spielfeld
        char eingabe;

        // Exceptions
        while(true) // Eingabe überprüfen
        {
            try
            {
                cin >> eingabe; // Eingane lesen
                if(cin.fail())
                {
                    cin.clear(); // Clear Fehlerzustand
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Input fehlgeschlagen"); // Exception werfen
                }
                else
                {
                    eingabe = tolower(eingabe); // Eingabe in Kleinbuchstaben
                    spieler->bewegen(eingabe); // Wird Bewegen Funktion aufgerufen
                    break;
                }
            }
            catch(const runtime_error& e)
            {
                cout << e.what(); // Exception ausgeben, falls Laufzeitfehler
            }
            catch(const invalid_argument& e)
            {
                cout << e.what(); // Exception ausgeben, falls ungültige Eingabe übergeben wird
            }
            catch(const range_error& e)
            {
                cout << e.what(); // Exception ausgeben, falls Wert außerhalb des ranges liegt
            }
        }
        char jetzt;
        jetzt = spiel->getFeld(spieler->getX(), spieler->getY()); // Aktuelles Feld
        spiel->resetFeld(spieler->getX(), spieler->getY()); // Aktuelles Feld wird leer
        switch(jetzt)
        {
        case '?':
            srand(time(NULL));
            if(rand() % 6 == 5) // 1/6 Chance auf Schaden
                spieler->minusLeben(); // Lebenspunkte -1
            break;
        case '~':
            spieler->plusLeben(); // Lebenspunkte +1
            break;
        case 'R':
            spieler->plusRelikte(); // Relikte sammeln
            break;
        }
        if(!spiel->relikteDa()) // Keine Relikte da = gewonnen
        {
            break;
        }
        if(!spieler->lebenspunkteDa()) // Keine Leben mehr = verloren
        {
            lebendig = false;
            break;
        }
    }
    if (lebendig)
    {
        cout << "Du hast gewonnen!" << endl;
    }
    else
    {
        cout << "Du hast verloren!" << endl;
    }
    delete spiel;
    delete spieler;
    return 0;
}
