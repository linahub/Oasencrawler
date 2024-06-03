#include "charakter.h"
#include <stdexcept> // Exceptions

charakter::charakter()
{
    //ctor
    this->x = 0;
    this->y = 0;
    this->lebenspunkte = 5; // Startlebenspunkte
    this->relikte = 0; // Startrelikte
}

charakter::~charakter()
{
    //dtor
}

// Operatoren und Exceptions
void charakter::bewegen(char richtung)
{
    switch(richtung)
    {
    case 'w':
        if(this->y != 0) // Wenn Spieler nicht ganz oben ist
            (*this)--; // Wird um eins nach oben geschoben
        else
            throw std::range_error("In die Richtung kann man nicht weitergehen!\n");
        break;
    case 'a':
        if(this->x != 0)
            --(*this); // Eins nach links
        else
            throw std::range_error("In die Richtung kann man nicht weitergehen!\n");
        break;
    case 's':
        if(this->y != 4) // Darf nicht unten am Rand sein <4
            (*this)++; // Eins nach runter
        else
            throw std::range_error("In die Richtung kann man nicht weitergehen!\n");
        break;
    case 'd':
        if(this->x != 4) // Darf nicht rechts am Rand sein <4
            ++(*this); // Eins nach rechts
        else
            throw std::range_error("In die Richtung kann man nicht weitergehen!\n");
        break;
    default:
        throw std::invalid_argument("Falsche Taste!\n");
        break;
    }
}
