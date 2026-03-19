#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int zieheKarte() {
    return rand() % 10 + 2;
}

int main() {

    srand(time(0));

    int spieler = 0, ki = 0;
    char BeginAnswer, SecondAnswer;

    cout << "Willkommen!" << endl;
    cout << "Wollen Sie eine Runde BlackJack spielen? [Y/n]: ";
    cin >> BeginAnswer;

    if (BeginAnswer == 'Y' || BeginAnswer == 'y') {
        cout << "Okay, lassen Sie uns eine Runde spielen!" << endl;

        // Startkarten
        spieler += zieheKarte();
        spieler += zieheKarte();
        ki += zieheKarte();
        ki += zieheKarte();

        cout << "Ihr Startwert: " << spieler << endl;

        // Spieler-Zug (mehrfach ziehen möglich)
        do {
            cout << "Wollen Sie eine weitere Karte ziehen? [Y/n]: ";
            cin >> SecondAnswer;

            if (SecondAnswer == 'y' || SecondAnswer == 'Y') {
                int karte = zieheKarte();
                spieler += karte;
                cout << "Sie ziehen: " << karte << endl;
                cout << "Ihr Punktestand: " << spieler << endl;

                if (spieler > 21) {
                    cout << "Sie haben verloren (Bust)!" << endl;
                    return 0;
                }
            }

        } while (SecondAnswer == 'y' || SecondAnswer == 'Y');

        // KI spielt erst JETZT
        cout << "\nKI ist am Zug..." << endl;

        while (ki < 17) {
            int karte = zieheKarte();
            ki += karte;
            cout << "KI zieht: " << karte << endl;
        }

        cout << "Punktestand KI: " << ki << endl;

        // Gewinner Modell
        if (ki > 21) {
            cout << "KI hat verloren! Du gewinnst!" << endl;
        }
        else if (spieler > ki) {
            cout << "Du gewinnst!" << endl;
        }
        else if (spieler < ki) {
            cout << "KI gewinnt!" << endl;
        }
        else {
            cout << "Unentschieden!" << endl;
        }

    } else {
        cout << "Programm wird beendet" << endl;
    }

    return 0;
}