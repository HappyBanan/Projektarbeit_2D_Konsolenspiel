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
 * Speicher allozieren für die Map
 * 
 * @param Höhe      Anzahl Zeilen
 * @param Breite    Anzahl Spalten
 */
void allocateMap(int Höhe, int Breite);

/**
 * Speicher freigeben für die Map
 * 
 * @param Höhe      Anzahl Zeilen
 */
void freeMap(int Höhe);

/**
 * Erstellt eine Karte mit den Dimensionen Höhe und Breite
 * Füllt das Array zu Werscheinlichkeit in % mit dem inhalt von 'Hindernis' 
 * Füllt den rest mit dem inhalt von 'Freiflaeche'
 * 
 * @param Höhe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Hindernis             Inhalt für Hindernisse auf der Map - m% Wahrscheinlichkeit
 * @param Freiflaeche           Inhalt für Freiflaeche auf der Map
 * @param Werscheinlichkeit     Prozentualer Anteil an Hindernissen
 */
void createMap(int Höhe, int Breite, char Hindernis, char Freiflaeche, int Werscheinlichkeit);

/**
 * Nimmt die Karte mit den Dimensionen Höhe und Breite
 * Generiert die Position der Spielers zufällig 
 * Plaziert den Spieler wenn da kein Hindernis oder Schatz ist
 * Giebt die Position des Spielers zurück
 * 
 * @param Höhe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Freiflaeche           Inhalt für Freiflaeche auf der Map
 * @param Spielers              Inhalt des Spielers auf der Map
 */
Position placePlayer(int Höhe, int Breite, char Freiflaeche, char Spielers);

/**
 * Nimmt die Karte mit den Dimensionen Höhe und Breite
 * Generiert die Position der Schatzes zufällig 
 * Plaziert den Schatz wenn da kein Hindernis oder Spieler ist
 * Giebt die Position des Schatzes zurück
 * 
 * @param Höhe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 * @param Hindernis             Inhalt für Hindernis auf der Map
 * @param Schatz                Inhalt des Schatz auf der Map
 * @param Spielers              Inhalt des Spielers auf der Map
 * 
 */
Position placeSchatz(int Höhe, int Breite, char Hindernis, char Schatz, char Spielers);

/**
 * Gibt ein Char Array mit den Dimensionen Höhe * Breite auf der Konsole aus
 * Höhe = Zeilen
 * Breite = Spalten
 * 
 * @param Höhe                  Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                Anz. Zeichen im Array - map[Höhe][Breite]
 */
void printMap(int Höhe, int Breite);

/**
 * Updatet die Map - ohne Ausgabe
 * 
 * @param Spieler_alt_Höhe       Spielerposition vor der Bewegung 
 * @param Spieler_alt_Breite     Spielerposition vor der Bewegung
 * @param Spieler_neu_Höhe       Spielerposition nach der Bewegung
 * @param Spieler_neu_Breite     Spielerposition nach der Bewegung
 * 
 * @param Freifläche             Inhalt für die alte Position (Freifläche)
 * @param Spieler                Inhalt für die neue Position (Spieler)
 */
void updateMap(int Spieler_alt_Höhe, int Spieler_alt_Breite, int Spieler_neu_Höhe, int Spieler_neu_Breite, char Freifläche, char Spieler);


/**
 * Kontrolle ob bewegung möglich -> ausserhalb der Map (return 0)
 * Kontrolle ob bewegung möglich -> Hindernis (return 1)
 * Kontrolle ob Spieler auf Schatz ist (return 2)
 * Map updaten - ohne Ausgabe (return 3)
 * 
 * @param Höhe                   Grösse des Arrays - map[Höhe][Breite] 
 * @param Breite                 Anz. Zeichen im Array - map[Höhe][Breite]
 * 
 * @param Spieler_alt_Höhe       Spielerposition vor der Bewegung 
 * @param Spieler_alt_Breite     Spielerposition vor der Bewegung
 * @param Spieler_neu_Höhe       Spielerposition nach der Bewegung
 * @param Spieler_neu_Breite     Spielerposition nach der Bewegung
 * 
 * @param Hindernis              Inhalt für die alte Position (Hindernis)
 * @param Freifläche             Inhalt für die alte Position (Freifläche)
 * @param Spieler                Inhalt für die neue Position (Spieler)
 * @param Schatz                 Inhalt für die neue Position (Schatz)
 */
int checkMap(int Höhe, int Breite, int Spieler_alt_Höhe, int Spieler_alt_Breite, int Spieler_neu_Höhe, int Spieler_neu_Breite, char Hindernis, char Freifläche, char Spieler, char Schatz);

#endif // MAP_H ENDE