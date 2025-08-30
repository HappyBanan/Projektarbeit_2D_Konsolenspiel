#ifndef MAP_H
#define MAP_H

#define MAX_Y 50 // Konstante für die maximale Spaltenzahl

// Struktur für die Position
typedef struct { 
    int x;
    int y;
} Position;

/**
* Initialisiert das Map Modul
* Muss vor allen anderen Funktionen aufgerufen werden
*/
void initMapModule();

/**
 * Erstellt eine Karte mit den Dimensionen x und y
 * Füllt das Array zu M% mit dem inhalt von 'i' 
 * Füllt den rest mit dem inhalt von 'j'
 * 
 * @param x   Grösse des Arrays - map[x][y] 
 * @param y   Anz. Zeichen im Array - map[x][y] - (MAX_Y = 50)
 * @param i   Inhalt für Hindernisse auf der Map - m% Wahrscheinlichkeit
 * @param j   Inhalt für Freiflaeche auf der Map
 * @param m   Prozentualer Anteil von i
 */
void createMap(int x, int y, char i, char j, int m);

/**
 * Nimmt die Karte mit den Dimensionen x und y
 * Generiert die Position der Spielers zufällig 
 * Plaziert den Spieler wenn da kein Hindernis oder Schatz ist
 * Giebt die Position des Spielers zurück
 * 
 * @param x   Grösse des Arrays - map[x][y] 
 * @param y   Anz. Zeichen im Array - map[x][y] - (MAX_Y = 50)
 * @param i   Inhalt für Hindernisse auf der Map
 * @param j   Inhalt des Schatzes auf der Map
 * @param m   Inhalt des Spielers auf der Map
 */
Position placePlayer(int x, int y, char i, char j);

/**
 * Nimmt die Karte mit den Dimensionen x und y
 * Generiert die Position der Schatzes zufällig 
 * Plaziert den Schatz wenn da kein Hindernis oder Spieler ist
 * Giebt die Position des Schatzes zurück
 * 
 * @param x   Grösse des Arrays - map[x][y] 
 * @param y   Anz. Zeichen im Array - map[x][y] - (MAX_Y = 50)
 * @param i   Inhalt für Hindernis auf der Map
 * @param j   Inhalt des Schatz auf der Map
 * @param m   Inhalt des Spielers auf der Map
 * 
 */
Position placeSchatz(int x, int y, char i, char j, char m);

/**
 * Gibt ein Char Array mit den Dimensionen x und y aus
 * x = Zeilen
 * y = Spalten
 * 
 * @param x   Grösse des Arrays - map[x][y] 
 * @param y   Anz. Zeichen im Array - map[x][y] - (MAX_Y = 50)
 */
void printMap(int x, int y);

/**
 * Updatet die Map - ohne Ausgabe
 * 
 * @param m       Spielerposition vor der Bewegung map[m][n]
 * @param n       Spielerposition vor der Bewegung map[m][n]
 * @param o       Spielerposition nach der Bewegung map[o][p]
 * @param p       Spielerposition nach der Bewegung map[o][p]
 * 
 * @param i       Inhalt für die alte Position (Freifläche)
 * @param j       Inhalt für die neue Position (Spieler)
 */
void updateMap(int m, int n, int o, int p, char i, char j);


/**
 * Kontrolle ob bewegung möglich -> ausserhalb der Map (return 0)
 * Kontrolle ob bewegung möglich -> Hindernis (return 1)
 * Kontrolle ob Spieler auf Schatz ist (return 2)
 * Map updaten - ohne Ausgabe (return 3)
 * 
 * @param x   Grösse des Arrays - map[x][y] 
 * @param y   Anz. Zeichen im Array - map[x][y] - (MAX_Y = 50)
 * 
 * @param m       Spielerposition vor der Bewegung map[m][n]
 * @param n       Spielerposition vor der Bewegung map[m][n]
 * @param o       Spielerposition nach der Bewegung map[o][p]
 * @param p       Spielerposition nach der Bewegung map[o][p]
 * 
 * @param h       Inhalt für die alte Position (Hindernis)
 * @param i       Inhalt für die alte Position (Freifläche)
 * @param j       Inhalt für die neue Position (Spieler)
 * @param k       Inhalt für die neue Position (Schatz)
 */
int checkMap(int x, int y, int m, int n, int o, int p, char h, char i, char j, char k);

#endif // MAP_H ENDE