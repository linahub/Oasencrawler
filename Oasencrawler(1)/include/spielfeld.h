#ifndef SPIELFELD_H
#define SPIELFELD_H

class charakter;
class spielfeld
{
    public:
        spielfeld();
        virtual ~spielfeld();
        void showField(charakter& spieler); // Zeigt das Spielfeld mit der Position des Spielers an
        char getFeld(int x, int y) { return this->field[x][y]; } // Gibt den Inhalt des Feldes an
        void resetFeld(int x, int y) { this-> field[x][y] = ' '; } // Feld wird leer, nach dem betreten
        bool relikteDa(); // Überprüft, true, wenn mindestens 1 Relikt auf Spielfeld da, ansolsten false

    protected:

    private:
        char field[5][5]; // Spielfeld
};

#endif // SPIELFELD_H
