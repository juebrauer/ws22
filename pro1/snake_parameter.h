// Spielparameter
#define GAME_SPEED 300

#define MAX_SCHLANGEN_LAENGE 100

#define HOEHE 30
#define BREITE 40

#define ITEM_WAND '#'
#define ITEM_LEER ' '
#define ITEM_FUTTER 'x'
#define ITEM_SCHLANGE_KOPF '@'
#define ITEM_SCHLANGE_SCHWANZ 'o'

#define COLOR_WAND "\x1B[32;47m"
#define COLOR_LEER "\x1B[0;47m"
#define COLOR_FUTTER "\x1B[36;47m"
#define COLOR_SCHLANGE_KOPF "\x1B[31;47m"
#define COLOR_SCHLANGE_SCHWANZ "\x1B[33;47m"

#define STARTFLAECHE_SEITENLAENGE 7
#define ANZAHL_START_FUTTERSTUECKE 10
#define ANZAHL_WAENDE 8
#define WAENDE_LAENGE 4

#define STARTDIR_X 1
#define STARTDIR_Y 0

#define INITIAL_SNAKE_LENGTH 4


/*
  	Color 	Foreground code 	Background code
0 	Black 	30 \x1b[30m 	40 \x1b[40m
1 	Red 	31 \x1b[31m 	41 \x1b[41m
2 	Green 	32 \x1b[32m 	42 \x1b[42m
3 	Yellow 	33 \x1b[33m 	43 \x1b[43m
4 	Blue 	34 \x1b[34m 	44 \x1b[44m
5 	Magenta	35 \x1b[35m 	45 \x1b[45m
6 	Cyan 	36 \x1b[36m 	46 \x1b[46m
7 	White 	37 \x1b[37m 	47 \x1b[47m
*/