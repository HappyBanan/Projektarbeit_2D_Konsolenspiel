#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Map.h"

// Globale Variable für die Map (Pointer auf Pointer)
char** map = NULL;

// Initialisiert das Map Modul (Zufallsgenerator)
void initMapModule() {
    srand(time(NULL));
}

// Speicher für die Map allozieren
void allocateMap(int Höhe, int Breite) {
    map = (char**)malloc(Höhe * sizeof(char*));          // Speicher für Zeilen reservieren
    for (int i = 0; i < Höhe; i++) {
        map[i] = (char*)malloc(Breite * sizeof(char));   // Speicher für Spalten reservieren
    }
}

// Speicher für die Map freigeben
void freeMap(int Höhe) {
    if (map != NULL) {
        for (int i = 0; i < Höhe; i++) {
            free(map[i]);                               // Speicher für jede Zeile freigeben
        }
        free(map);                                      // Speicher für die Zeilenzeiger freigeben
        map = NULL;                                     // Pointer zurücksetzen
    }
}

// Routinen zum erstellen der Map
void createMap(int Höhe, int Breite, char Hindernis, char Freiflaeche, int Werscheinlichkeit) {
    
    for (int h = 0; h < Höhe; h++) {                    // Schleife für die Höhe    
        for (int b = 0; b < Breite; b++) {              // Schleife für die Breite
            if (rand() % 100 < Werscheinlichkeit) {     // Fülle die Map zu Werscheinlichkeit % mit inhalt aus Hindernis, sonst aus Freiflaeche
                map[h][b] = Hindernis;
            } else {
                map[h][b] = Freiflaeche;
            }
        }
    }
}

// Routinen zum plazieren des Spielers - Rückgabe der Position des Spielers
Position placePlayer(int Höhe, int Breite, char Freiflaeche, char Spielers) {  

    int plaziert = 0;                                   // Marker ob plaziert
    Position pos;                                       // Position des Spielers initialisieren
   
    while (!plaziert) {                                 // Spieler plaziert?              
        int h = rand() % (Höhe);                        // Zufallszahl für Höhe
        int b = rand() % (Breite);                      // Zufallszahl für Breite
        if (map[h][b] == Freiflaeche) {                 // Nur belegen wenn inhalt aus Position = char Freiflaeche
            map[h][b] = Spielers;                       // Spieler plazieren

            pos.x = h;                                  // Position speichern
            pos.y = b;

            plaziert = 1;                               // Schleife beenden
        
        }
    }
    return pos;
}

// Routinen zum plazieren des Schatzes - Rückgabe der Position des Schatzes
Position placeSchatz(int Höhe, int Breite, char Hindernis, char Schatz, char Spielers) {  

    int plaziert = 0;                                   // Marker ob plaziert
    Position pos;                                       // Position des Schatzes initialisieren
   
    while (!plaziert) {                                 // Spieler plaziert?              
        int h = rand() % (Höhe);                        // Zufallszahl für Höhe
        int b = rand() % (Breite);                      // Zufallszahl für Breite
        if (map[h][b] != Hindernis && map[h][b] != Spielers) { // Nur belegen wenn nicht Buchstabe i oder m
            map[h][b] = Schatz;                         // Schatz plazieren 

            pos.x = h;                                  // Position speichern
            pos.y = b;

            plaziert = 1;                               // Schleife beenden
        }
    }
    return pos;
}

// Routinen zum ausgeben der Map
void printMap(int Höhe, int Breite) {
    printf("\n");                                       // Leere Zeile vor der Map    
    for (int i = 0; i < Höhe; i++) {                    // Zeilen Schleife
        for (int j = 0; j < Breite; j++) {              // Spalten Schleife
            printf("%c ", map[i][j]);                   // Ausgabe Zeichen
        }
    printf("\n");                                       // Neue Zeile beginnen
    }
    printf("\n");                                       // Leere Zeile nach der Map
}

// Routinen zum updaten der Map (Bewegung des Spielers)
void updateMap(int Spieler_alt_Höhe, int Spieler_alt_Breite, int Spieler_neu_Höhe, int Spieler_neu_Breite, char Freifläche, char Spieler) {
    map[Spieler_alt_Höhe][Spieler_alt_Breite] = Freifläche;     // Alte Position mit char Freifläche füllen
    map[Spieler_neu_Höhe][Spieler_neu_Breite] = Spieler;        // Neue Position mit char Spieler füllen
}

// Kontrolliere die Bewegung des Spielers
int checkMap(int Höhe, int Breite, int Spieler_alt_Höhe, int Spieler_alt_Breite, int Spieler_neu_Höhe, int Spieler_neu_Breite, char Hindernis, char Freifläche, char Spieler, char Schatz) {
    if (Spieler_neu_Höhe < 0 || Spieler_neu_Höhe >= Höhe || Spieler_neu_Breite < 0 || Spieler_neu_Breite >= Breite) {                   // Ausserhalb der Map?
        return 0;                                                       // 0 == Bewegung nicht möglich
    }
    else if (map[Spieler_neu_Höhe][Spieler_neu_Breite] == Hindernis) {  // Auf Hindernis?
        return 1;                                                       // 1 == Bewegung nicht möglich
    }
    else if (map[Spieler_neu_Höhe][Spieler_neu_Breite] == Schatz) {     // Auf Schatz? -> Map updaten
        updateMap( Spieler_alt_Höhe, Spieler_alt_Breite, Spieler_neu_Höhe, Spieler_neu_Breite, Freifläche, Spieler);
        return 2;                                                       // 1 == Spiel gewonnen
    } 
    else {                                                              // Kein Problem? -> Map updaten
        updateMap( Spieler_alt_Höhe, Spieler_alt_Breite, Spieler_neu_Höhe, Spieler_neu_Breite, Freifläche, Spieler);
        return 3;                                                       // 2 == Bewegung erfolgreich
    }
}