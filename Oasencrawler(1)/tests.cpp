#define CATCH_CONFIG_MAIN // Catch2
#include "catch.hpp" // Catch2 Bibliothek
#include "charakter.h"
#include "spielfeld.h"

// Unittests für die Charakter Klasse; Siehe Unit Tests PPP Seite 29
TEST_CASE("charakter Test", "[charakter]")
{
    charakter spieler;
    // Testfälle für Konstruktor und Getter
    SECTION("Konstruktor und Getter")
    {
        REQUIRE(spieler.getX() == 0); // Überprüfen der x-Koordinate
        REQUIRE(spieler.getY() == 0); // Überprüfen der y-Koordinate
        REQUIRE(spieler.getLebenspunkte() == 5); // Überprüfen der Lebenspunkte
    }

    // Testfälle für Bewegung, "wasd", rauf, links, runter, rechts
    SECTION("Bewegung")
    {
        spieler.bewegen('s');
        REQUIRE(spieler.getY() == 1); // Überprüfen, ob Spieler sich nach unten bewegt hat
        spieler.bewegen('w');
        REQUIRE(spieler.getY() == 0); // Überprüfen, ob Spieler nicht nach oben bewegt hat (y = 0)
        spieler.bewegen('d');
        REQUIRE(spieler.getX() == 1); // Überprüfen, ob Spieler sich nach rechts bewegt hat
        spieler.bewegen('a');
        REQUIRE(spieler.getX() == 0); // Überprüfen, ob Spieler nicht nach links bewegt hat (x = 0)
    }

    // Testfall für Minus Lebenspunkte
    SECTION("LebenMinus")
    {
        spieler.minusLeben();
        REQUIRE(spieler.getLebenspunkte() == 4); // Überprüfen, ob Spieler ein Leben verloren hat
    }

    // Testfall für Plus Lebenspunkte
    SECTION("LebenPlus")
    {
        spieler.plusLeben();
        REQUIRE(spieler.getLebenspunkte() == 6); // Überprüfen, ob Spieler ein Leben gewonnen hat
    }

    // Testfall für das Sammeln von Relikten
    SECTION("Relikte")
    {
        spieler.plusRelikte();
        REQUIRE(spieler.getRelikte() == 1); // Überprüfen, ob Spieler ein Relikt gesammelt hat
    }

    // Testfall, ob Spieler noch Lebenspunkte hat
    SECTION("LebenspunkteDa")
    {
        REQUIRE(spieler.lebenspunkteDa()); // Überprüfen, ob Spieler noch Lebenspunkte hat
        for (int i = 0; i < 5; ++i)
            spieler.minusLeben();
        REQUIRE_FALSE(spieler.lebenspunkteDa()); // Überprüfen, ob Spieler keine Lebenspunkte mehr hat
    }
}

// Unittests für die Spielfeld Klasse
TEST_CASE("spielfeld Test", "[spielfeld]")
{
    spielfeld spiel;
    // Testfall für die Initialisierung des Spielfelds
    SECTION("Initialisierung")
    {
        REQUIRE(spiel.getFeld(0, 0) == ' '); // Überprüfen, ob Startfeld richtig initialisiert wurde
        bool reliktExists = false;
        // Überprüfen, ob mindestens ein Relikt da ist
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (i == 0 && j == 0) continue; // Startfeld überspringen
                char feld = spiel.getFeld(i, j);
                if (feld == 'R') reliktExists = true;
            }
        }
        REQUIRE(reliktExists);
    }

    // Testfall für die Methode relikteDa
    SECTION("RelikteDa")
    {
        REQUIRE(spiel.relikteDa() == true); // Überprüfen, ob Relikte da sind
        // Überprüfen, ob keine Relikte mehr da sind
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
