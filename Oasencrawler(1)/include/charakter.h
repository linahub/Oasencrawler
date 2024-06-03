#ifndef CHARAKTER_H
#define CHARAKTER_H


class charakter
{
    public:
        charakter();
        virtual ~charakter();
        void bewegen(char richtung); // Bewegt Charakter
        int getX() { return this->x; }
        int getY() { return this->y; }
        void minusLeben() { this->lebenspunkte--; } // Lebenspunkt -1
        void plusLeben() { this->lebenspunkte++; } // Lebenspunkt +1
        void plusRelikte() { this->relikte++; } // Relikt gesammelt +1
        bool lebenspunkteDa() { return this->lebenspunkte != 0; } //�berpr�ft, ob Charakter noch Lebenspunkte hat; True/false
        int getLebenspunkte () { return lebenspunkte; } // int die aktuellen Lebenspunkte des Charakters
        int getRelikte () { return relikte; } // int die Anzahl der gesammelten Relikte

        // Operatoren
        charakter& operator++() { // x wird von Pr�fix inkrementiert und dekrementiert
            ++x; // Pr�fix f�r x, erh�hen = bewegen nach unten
            return *this;
        }
        charakter& operator--() {
            --x; // Pr�fix f�r x, verringern = bewegen nach oben
            return *this;
        }
        charakter& operator++(int) { // y wird von Suffix inkrementiert und dekrementiert
            y++; // Suffix f�r y, erh�hen = bewegen nach rechts
            return *this;
        }
        charakter& operator--(int) {
            y--; // Suffix f�r y, verringern = bewegen nach links
            return *this;
        }

    protected:

    private:
        int x;
        int y;
        int lebenspunkte; // Aktuelle Lebenspunkte des Charakters
        int relikte; // Anzahl der gesammelten Relikte
};

#endif // CHARAKTER_H
