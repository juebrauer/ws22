#include <stdio.h> // printf()
#include <stdlib.h> // rand()
#include <time.h>   // time()

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  //newt.c_lflag &= ~(ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}


void EchoEnable(int EchoOn)
{
    struct termios TermConf;

    tcgetattr(STDIN_FILENO, &TermConf);

    if(EchoOn)
       TermConf.c_lflag |= (ICANON | ECHO);
    else
       TermConf.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &TermConf);
}


// Spielparameter
#define HOEHE 30
#define BREITE 40

#define ITEM_WAND '#'
#define ITEM_LEER ' '
#define ITEM_FUTTER 'x'
#define ITEM_SCHLANGE_KOPF '@'

#define STARTFLAECHE_SEITENLAENGE 5
#define ANZAHL_START_FUTTERSTUECKE 10
#define ANZAHL_WAENDE 8
#define WAENDE_LAENGE 4

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

#define cursor_hide() printf("\e[?25l")
#define cursor_show() printf("\e[?25h")


char spielfeld[HOEHE][BREITE];

// Startposition der Schlange: Spielfeldmitte
int sx = BREITE/2;
int sy = HOEHE/2;

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
        int startx = 1 + rand() % (BREITE-2);
        int starty = 1 + rand() % (HOEHE-2-(linien_laenge-1));
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
        int startx = 1 + rand() % (BREITE-2-(linien_laenge-1));
        int starty = 1 + rand() % (HOEHE-2);
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
         int x = 1 + rand() % (BREITE-2);
         int y = 1 + rand() % (HOEHE-2);
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

    char ganzes_spielfeld_als_str[HOEHE*(BREITE+3)];

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
        ganzes_spielfeld_als_str[i]   = ' ';
        ganzes_spielfeld_als_str[i+1] = ' ';
        ganzes_spielfeld_als_str[i+2] = '\n';
        i = i + 3;
    }
    
    printf("%s\n", ganzes_spielfeld_als_str);
    printf("Update: %lld\n", update);
    printf("Schlangen-Position: (%d,%d)", sx, sy);
    
    
} // spielfeld_zeichnen


void bewege_schlange(char taste)
{
    switch (taste)
    {
        case 'w' : if (sy>1)        sy-=1; break;
        case 's' : if (sy<HOEHE-2)  sy+=1; break;
        case 'a' : if (sx>1)        sx-=1; break;
        case 'd' : if (sx<BREITE-2) sx+=1; break;
    }
}



int main()
{
    // Pseudozufallszahlengenerator zufällig
    // initialisieren
    int startwert = time(NULL);    
    srand( startwert );

    int game_over = 0;

    spielfeld_aufbauen();
    spielfeld[sy][sx] = ITEM_SCHLANGE_KOPF;
    

    clear();
    cursor_hide();
    EchoEnable(0);

    char benutzer_eingabe;
    
    // Spielablaufschleife    
    do
    {        
        gotoxy(0,0);        
        spielfeld_zeichnen();

        if (kbhit())
        {
            gotoxy(0, HOEHE+1);
            benutzer_eingabe = getchar();

            // Wenn der Benutzer die ESC-Taste drückt,
            // springen wir aus der Spielablaufschleife
            if (benutzer_eingabe == 27)
                break;            
            
            spielfeld[sy][sx] = ITEM_LEER;
            bewege_schlange( benutzer_eingabe );
            spielfeld[sy][sx] = ITEM_SCHLANGE_KOPF;
        }

        // Benutzereingabe zur Schlangensteuerung

    } while (game_over == 0);

    printf("Benutzer hat folgende Taste gedrückt: %c\n", benutzer_eingabe);

    cursor_show();

    return 0;
    
} // main