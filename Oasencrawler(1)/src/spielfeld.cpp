#include "charakter.h"
#include "spielfeld.h"
#include <stdlib.h> // Zufallsfunktionen
#include <time.h> // Zeitfunktionen
#include <iostream> // Ein-/Ausgabe

spielfeld::spielfeld()
{
    //ctor initialisiert das Spielfeld mit zufälligen Inhalten, Gefahrenfelder, Brunnen und Relikte
    srand (time(NULL)); // Zufallszahlengenerator
    int result;
    bool reliktExists = false;
    this->field[0][0] = ' '; // Startfeld = leer initalisiert
    for(int i=0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 0) j++; // Feld vom Spieler überspringen
            result = rand() % 10; // Zufallszahl 0-9
            if(result < 4) // 0-3, 4/10 für leeres Feld ' '
            {
                field[i][j] = ' ';
            }
            else if(result < 8) // 4-7, 4/10 für Gefahrenfeld '?'
            {
                field[i][j] = '?';
            }
            else if(result == 8) // 8, 1/10 für Brunnen '~'
            {
                field[i][j] = '~';
            }
            else
            {
                field[i][j] = 'R'; // 9, 1/10 für Relikte 'R'
                reliktExists = true; // Mindestens 1 Relikt
            }
        }
    }
    if(!reliktExists)
    {
        field[2][2] = 'R'; // Wenn kein Relikt da, wird R in die Mitte des Spielfelds platziert
    }
}

spielfeld::~spielfeld()
{
    //dtor
}

void spielfeld::showField(charakter& spieler)
{
    std::cout << "Lebenspunkte: " << spieler.getLebenspunkte() << std::endl;

    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            if(spieler.getX() == x && spieler.getY() == y) // Spielerposition
                std::cout << "S" << " ";
            else
                std::cout << this->field[x][y] << " ";
        }
        std::cout << "\n";
    }
}

bool spielfeld::relikteDa () // True, wenn >=1 Relikt, sonst false
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(this->field[i][j] == 'R') return true;
        }
    }
    return false;
}
