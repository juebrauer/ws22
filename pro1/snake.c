#include <stdio.h> // printf()
#include <stdlib.h> // rand()
#include <time.h>   // time()


#include "snake_hilfsfunktionen.h"
#include "snake_parameter.h"



char spielfeld[HOEHE][BREITE];

// Startlaufrichtung der Schlange: nach rechts
int dx = STARTDIR_X;
int dy = STARTDIR_Y;

// Schlangenlänge
int sl = INITIAL_SNAKE_LENGTH;

// Datenstrukturen für die Schlangenkörperteilpositionen
int sx[MAX_SCHLANGEN_LAENGE];
int sy[MAX_SCHLANGEN_LAENGE];



// Wie oft wurde das Spielfeld schon neu gezeichnet?
unsigned long long update = 0;


void spielfeld_aufbauen_begrenzungsrahmen()
{
    // Begrenzungsrahmen ins Spielfeld zeichnen
    for (int y=0; y<HOEHE; y=y+1)
    {        
        // Sind wir in der ersten oder letzten
        // Zeile des Spielfeldes?
        // Wenn ja, dann Linie durchgehend
        // zeichnen
        if ((y==0) || (y==HOEHE-1))
        {
            for (int x=0; x<BREITE; x=x+1)
                spielfeld[y][x] = ITEM_WAND;
        }
        else
        {
            for (int x=1; x<BREITE-1; x=x+1)
            {
                spielfeld[y][x] = ITEM_LEER;
            }
            spielfeld[y][0] = ITEM_WAND;
            spielfeld[y][BREITE-1] = ITEM_WAND;
        }
    }
} // spielfeld_aufbauen_begrenzungsrahmen


void spielfeld_aufbauen_hindernisse_vertikal(int anz_linien,
                                             int linien_laenge)
{
    // Zufällige vertikale Hindernisse einzeichnen
    for (int linien_nr=1; linien_nr<=anz_linien; linien_nr=linien_nr+1)
    {                        
        int startx = zufallszahl(1, BREITE-2);
        int starty = zufallszahl(1, HOEHE-2-(linien_laenge-1));        
        for (int linien_stueck=0;
             linien_stueck<linien_laenge;
             linien_stueck=linien_stueck+1)
        {
            int x,y;
            x = startx;
            y = starty + linien_stueck;
            spielfeld[y][x] = ITEM_WAND;
        }
    }
} // spielfeld_aufbauen_hindernisse_vertikal



void spielfeld_aufbauen_hindernisse_horizontal(int anz_linien,
                                               int linien_laenge)
{
    // Zufällige horizontale Hindernisse einzeichnen
    for (int linien_nr=1; linien_nr<=anz_linien; linien_nr=linien_nr+1)
    {
        int startx = zufallszahl(1, BREITE-2-(linien_laenge-1));
        int starty = zufallszahl(1, HOEHE-2);
        for (int linien_stueck=0;
             linien_stueck<linien_laenge;
             linien_stueck=linien_stueck+1)
        {
            int x,y;
            x = startx + linien_stueck;
            y = starty;
            spielfeld[y][x] = ITEM_WAND;
        }
    }
} // spielfeld_aufbauen_hindernisse_horizontal


void spielfeld_aufbauen_futter(int anz_futterstuecke)
{
    for (int stueck_nr=0; stueck_nr<anz_futterstuecke; stueck_nr=stueck_nr+1)
    {
         int x = zufallszahl(1, BREITE-2);
         int y = zufallszahl(1, HOEHE-2);
         spielfeld[y][x] = ITEM_FUTTER;
    }
}


void spielfeld_aufbauen_startflaeche(int seitenlaenge)
{
    int mitte_x = BREITE/2;
    int mitte_y = HOEHE/2;
    for (int oy=-seitenlaenge/2; oy<=seitenlaenge/2; oy=oy+1)
    {
        for (int ox=-seitenlaenge/2; ox<=seitenlaenge/2; ox=ox+1)
        {
            int x = mitte_x + ox;
            int y = mitte_y + oy;
            spielfeld[y][x] = ITEM_LEER;
        }
    }
} // spielfeld_aufbauen_startflaeche


void spielfeld_aufbauen()
{
    spielfeld_aufbauen_begrenzungsrahmen();
    spielfeld_aufbauen_hindernisse_vertikal( ANZAHL_WAENDE, WAENDE_LAENGE );
    spielfeld_aufbauen_hindernisse_horizontal( ANZAHL_WAENDE, WAENDE_LAENGE );    
    spielfeld_aufbauen_startflaeche( STARTFLAECHE_SEITENLAENGE );
    spielfeld_aufbauen_futter( ANZAHL_START_FUTTERSTUECKE );

} // spielfeld_aufbauen


void spielfeld_zeichnen()
{    
    update += 1;

    char ganzes_spielfeld_als_str[HOEHE*(BREITE+1)];

    // Für alle Zeilen ...
    int i = 0;
    for (int y=0; y<HOEHE; y=y+1)
    { 
        // Für alle Spalten ...
        for (int x=0; x<BREITE; x=x+1)
        {
            //printf("%c", spielfeld[y][x]);
            ganzes_spielfeld_als_str[i] = spielfeld[y][x];
            i = i + 1;
        }
        //printf("\n");
        ganzes_spielfeld_als_str[i] = '\n';
        i = i + 1;
    }
    
    gotoxy(0,0);
    printf("%s\n", ganzes_spielfeld_als_str);
    printf("Update: %lld\n", update);
    printf("Schlangen-Position: (%d,%d) \n", sx[0], sy[0]);
    printf("Schlangen-Länge: %d\n", sl);
    
    
} // spielfeld_zeichnen


void aendere_schlangen_laufrichtung(char taste)
{    
    switch (taste)
    {
        case 65 : dy=-1; dx=0;  break; // oben
        case 66 : dy=+1; dx=0;  break; // unten
        case 68 : dy=0;  dx=-1; break; // links
        case 67 : dy=0;  dx=+1; break; // rechts
    }
}



int main()
{
    // Pseudozufallszahlengenerator zufällig
    // initialisieren
    int startwert = time(NULL);    
    srand( startwert );

    int game_over = 0;

    // Lasse die Schlange in der Spielfeldmitte starten
    sy[0] = HOEHE/2;
    sx[0] = BREITE/2;
    for (int i=1; i<sl; i=i+1)
    {
        // Setze die nächste Position für das
        // nächste Schwanzteil der Schlange
        sx[i] = sx[i-1] - 1;
        sy[i] = sy[i-1];
    }

    spielfeld_aufbauen();
    spielfeld[sy[0]][sx[0]] = ITEM_SCHLANGE_KOPF;
    

    clear();
    cursor_hide();

    // Ausschalten der Anzeige der Benutzereingaben
    EchoEnable(0);

    char taste;
    
    // Spielablaufschleife    
    do
    {  
        // Schlange bewegen

         // Lösche letztes Schlangenteil aus dem Spielfeld
        spielfeld[sy[sl-1]][sx[sl-1]] = ITEM_LEER;

        // Rechne neue Schlangenkopfposition aus
        int new_sx = sx[0] + dx;
        int new_sy = sy[0] + dy;
        
        // Schlange in Wand gelaufen?
        // oder
        // Schlange in den eigenen Schwanz gelaufen?
        // @oooo (Länge: 5)
        // KSSSS
        if ( (spielfeld[new_sy][new_sx] == ITEM_WAND) ||
             (spielfeld[new_sy][new_sx] == ITEM_SCHLANGE_SCHWANZ)
            )
        {
            // Schlangenkopf läuft in Wand! Game Over!
            game_over = 1;
        }

        // Schlange in Futterstückchen gelaufen?
        if (spielfeld[new_sy][new_sx] == ITEM_FUTTER)
        {            
            // Rücke die Schlangenkörperteile im Array
            // eine Position nach hinten
            for (int i=sl; i>=1; i=i-1)
            {                
                sx[i] = sx[i-1];
                sy[i] = sy[i-1];
            }            
            // Berechne neue Schlangenlänge
            sl=sl+1;         
        }

        // Rücke Körperteile der Schlange nach
        for (int i=sl-1; i>=1; i=i-1)
        {
            sx[i] = sx[i-1];
            sy[i] = sy[i-1];
        }
        // Trage die neue Kopfposition ein
        sx[0] = new_sx;
        sy[0] = new_sy;

        // Zeichne die ganze Schlange
        // in das Spielfeld
        for (int i=0; i<sl; i=i+1)
        {
            char zeichen = ITEM_SCHLANGE_SCHWANZ;
            if (i==0)
                zeichen = ITEM_SCHLANGE_KOPF;
            spielfeld[sy[i]][sx[i]] = zeichen;
        }
        
        // Hat der Benutzer eine Taste gedrückt?
        if (kbhit())
        {
            // Ja!
            //gotoxy(0, HOEHE+1);
            taste = getchar();
            
            // Ist es eine Sondertaste?
            if (taste == 27)            
            {
                // Ja!

                // Ist sonst nichts mehr im Tastaturpuffer?
                if (kbhit()==0)                
                    break;
                else
                {
                    // Da ist noch was im Tastaturpuffer,
                    // es könnte eine Cursortaste sein!
                    char taste2 = getchar();                    

                    // Wurde die Cursor-Taste gedrückt?
                    if (taste2==91)
                    {
                        // Ja! Eine der Cursor-Tasten wurde gedrückt!
                        char taste3 = getchar();
                        aendere_schlangen_laufrichtung(taste3);
                    }
                }
            }
        }
              
        spielfeld_zeichnen();

        msleep( GAME_SPEED );

    } while (game_over == 0);

    gotoxy(0,HOEHE+5);

    if (game_over==1)
    {        
        printf("GAME OVER!\n");
    }

    //printf("Benutzer hat folgende Taste gedrückt: %c\n", benutzer_eingabe);

    // Einschalten der Anzeige der Benutzereingaben
    EchoEnable(1);

    cursor_show();

    return 0;
    
} // main