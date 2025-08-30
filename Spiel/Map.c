#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Map.h"

// Erzeuge Char Array für die Map
char map[MAX_Y][MAX_Y];

// Initialisiert das Map Modul (Zufallsgenerator)
void initMapModule() {
    srand(time(NULL));
}

// Routinen zum erstellen der Map
void createMap(int x, int y, char i, char j, int m) {
    
    for (int h = 0; h < x; h++) {               // Schleife für die Höhe    
        for (int b = 0; b < y; b++) {           // Schleife für die Breite
            if (rand() % 100 < m) {             // Fülle die Map zu m% mit inhalt von i, sonst von j
                map[h][b] = i;
            } else {
                map[h][b] = j;
            }
        }
    }
}

// Routinen zum plazieren des Spielers - Rückgabe der Position des Spielers
Position placePlayer(int x, int y, char i, char j) {  

    int plaziert = 0;                           // Marker ob plaziert
    Position pos;                               // Position des Spielers initialisieren
   
    while (!plaziert) {                         // Spieler plaziert?              
        int h = rand() % (x);                   // Zufallszahl für Höhe
        int b = rand() % (y);                   // Zufallszahl für Breite
        if (map[h][b] == i) {                   // Nur belegen wenn inhalt aus Position = char j
            map[h][b] = j;                      // Spieler plazieren

            pos.x = h;                          // Position speichern
            pos.y = b;

            plaziert = 1;                       // Schleife beenden
        
        }
    }
    return pos;
}

// Routinen zum plazieren des Schatzes - Rückgabe der Position des Schatzes
Position placeSchatz(int x, int y, char i, char j, char m) {  

    int plaziert = 0;                           // Marker ob plaziert
    Position pos;                               // Position des Schatzes initialisieren
   
    while (!plaziert) {                         // Spieler plaziert?              
        int h = rand() % (x);                   // Zufallszahl für Höhe
        int b = rand() % (y);                   // Zufallszahl für Breite
        if (map[h][b] != i && map[h][b] != m) { // Nur belegen wenn nicht Buchstabe i oder m
            map[h][b] = j;                      // Schatz plazieren 

            pos.x = h;                          // Position speichern
            pos.y = b;

            plaziert = 1;                       // Schleife beenden
        }
    }
    return pos;
}

// Routinen zum ausgeben der Map
void printMap(int x, int y) {
    printf("\n");               // Leere Zeile vor der Map    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c ", map[i][j]);
        }
    printf("\n");  
    }
    printf("\n");               // Leere Zeile nach der Map
}

// Routinen zum updaten der Map (Bewegung des Spielers)
void updateMap(int m, int n, int o, int p, char i, char j) {
    map[m][n] = i;   // Alte Position mit char i füllen
    map[o][p] = j;   // Neue Position mit char j füllen
}

// Kontrolliere die Bewegung des Spielers
int checkMap(int x, int y, int m, int n, int o, int p, char h, char i, char j, char k) {
    if (o < 0 || o >= x || p < 0 || p >= y) {       // Ausserhalb der Map?
        return 0;                                   // 0 == Bewegung nicht möglich
    }
    else if (map[o][p] == h) {                      // Auf Hindernis?
        return 1;                                   // 1 == Bewegung nicht möglich
    }
    else if (map[o][p] == k) {                      // Auf Schatz?
        updateMap(m, n, o, p, i, j);                // Map updaten
        return 2;                                   // 1 == Spiel gewonnen
    } 
    else {                                          // Auf freier Fläche?
        updateMap(m, n, o, p, i, j);                // Map updaten
        return 3;                                   // 2 == Bewegung erfolgreich
    }
}