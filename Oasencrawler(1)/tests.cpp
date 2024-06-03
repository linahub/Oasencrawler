#define CATCH_CONFIG_MAIN // Catch2
#include "catch.hpp" // Catch2 Bibliothek
#include "charakter.h"
#include "spielfeld.h"

// Unittests f�r die Charakter Klasse; Siehe Unit Tests PPP Seite 29
TEST_CASE("charakter Test", "[charakter]")
{
    charakter spieler;
    // Testf�lle f�r Konstruktor und Getter
    SECTION("Konstruktor und Getter")
    {
        REQUIRE(spieler.getX() == 0); // �berpr�fen der x-Koordinate
        REQUIRE(spieler.getY() == 0); // �berpr�fen der y-Koordinate
        REQUIRE(spieler.getLebenspunkte() == 5); // �berpr�fen der Lebenspunkte
    }

    // Testf�lle f�r Bewegung, "wasd", rauf, links, runter, rechts
    SECTION("Bewegung")
    {
        spieler.bewegen('s');
        REQUIRE(spieler.getY() == 1); // �berpr�fen, ob Spieler sich nach unten bewegt hat
        spieler.bewegen('w');
        REQUIRE(spieler.getY() == 0); // �berpr�fen, ob Spieler nicht nach oben bewegt hat (y = 0)
        spieler.bewegen('d');
        REQUIRE(spieler.getX() == 1); // �berpr�fen, ob Spieler sich nach rechts bewegt hat
        spieler.bewegen('a');
        REQUIRE(spieler.getX() == 0); // �berpr�fen, ob Spieler nicht nach links bewegt hat (x = 0)
    }

    // Testfall f�r Minus Lebenspunkte
    SECTION("LebenMinus")
    {
        spieler.minusLeben();
        REQUIRE(spieler.getLebenspunkte() == 4); // �berpr�fen, ob Spieler ein Leben verloren hat
    }

    // Testfall f�r Plus Lebenspunkte
    SECTION("LebenPlus")
    {
        spieler.plusLeben();
        REQUIRE(spieler.getLebenspunkte() == 6); // �berpr�fen, ob Spieler ein Leben gewonnen hat
    }

    // Testfall f�r das Sammeln von Relikten
    SECTION("Relikte")
    {
        spieler.plusRelikte();
        REQUIRE(spieler.getRelikte() == 1); // �berpr�fen, ob Spieler ein Relikt gesammelt hat
    }

    // Testfall, ob Spieler noch Lebenspunkte hat
    SECTION("LebenspunkteDa")
    {
        REQUIRE(spieler.lebenspunkteDa()); // �berpr�fen, ob Spieler noch Lebenspunkte hat
        for (int i = 0; i < 5; ++i)
            spieler.minusLeben();
        REQUIRE_FALSE(spieler.lebenspunkteDa()); // �berpr�fen, ob Spieler keine Lebenspunkte mehr hat
    }
}

// Unittests f�r die Spielfeld Klasse
TEST_CASE("spielfeld Test", "[spielfeld]")
{
    spielfeld spiel;
    // Testfall f�r die Initialisierung des Spielfelds
    SECTION("Initialisierung")
    {
        REQUIRE(spiel.getFeld(0, 0) == ' '); // �berpr�fen, ob Startfeld richtig initialisiert wurde
        bool reliktExists = false;
        // �berpr�fen, ob mindestens ein Relikt da ist
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == 0 && j == 0) continue; // Startfeld �berspringen
                char feld = spiel.getFeld(i, j);
                if (feld == 'R') reliktExists = true;
            }
        }
        REQUIRE(reliktExists);
    }

    // Testfall f�r die Methode relikteDa
    SECTION("RelikteDa")
    {
        REQUIRE(spiel.relikteDa() == true); // �berpr�fen, ob Relikte da sind
        // �berpr�fen, ob keine Relikte mehr da sind
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (spiel.getFeld(i, j) == 'R') {
                    spiel.resetFeld(i, j);
                }
            }
        }
        REQUIRE(spiel.relikteDa() == false);
    }
}
