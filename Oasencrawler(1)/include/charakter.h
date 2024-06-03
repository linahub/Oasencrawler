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
        bool lebenspunkteDa() { return this->lebenspunkte != 0; } //Überprüft, ob Charakter noch Lebenspunkte hat; True/false
        int getLebenspunkte () { return lebenspunkte; } // int die aktuellen Lebenspunkte des Charakters
        int getRelikte () { return relikte; } // int die Anzahl der gesammelten Relikte

        // Operatoren
        charakter& operator++() { // x wird von Präfix inkrementiert und dekrementiert
            ++x; // Präfix für x, erhöhen = bewegen nach unten
            return *this;
        }
        charakter& operator--() {
            --x; // Präfix für x, verringern = bewegen nach oben
            return *this;
        }
        charakter& operator++(int) { // y wird von Suffix inkrementiert und dekrementiert
            y++; // Suffix für y, erhöhen = bewegen nach rechts
            return *this;
        }
        charakter& operator--(int) {
            y--; // Suffix für y, verringern = bewegen nach links
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
