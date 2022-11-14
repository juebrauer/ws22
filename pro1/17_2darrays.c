#include <stdio.h>

#define HOEHE 3
#define BREITE 4

void foo(int* arr, int h, int b)
{
    int i = 0;
    int wert = 100;
    for (int y=0; y<h; y++)
        for (int x=0; x<b; x++)
        {
            *(arr+i) = wert;
            i++;
            wert++;
        }
}

int main()
{
    int A[HOEHE][BREITE];

    // 1. 2D-Array initialisieren
    int i=0;
    for (int y=0; y<HOEHE; y++)
    {
        for (int x=0; x<BREITE; x++)
        {
            A[y][x] = i;
            i++;
        }
    }

    // 2. Das 2D Array 2D-dimensional ausgeben
    for (int y=0; y<HOEHE; y++)
    {
        for (int x=0; x<BREITE; x++)
        {
            printf("A[%d][%d]=%02d  ", y,x, A[y][x]);            
        }
        printf("\n");
    }


    // 3. Speicheradressen des 2D Arrays ausgeben
    for (int y=0; y<HOEHE; y++)
    {
        for (int x=0; x<BREITE; x++)
        {
            printf("A[%d][%d]=%p  ", y,x, &(A[y][x]));            
        }
        printf("\n");
    }

    // 4. Das 2D Array innerhalb der Funktion foo() verändern
    foo(&(A[0][0]), HOEHE, BREITE);

    // 5. Das 2D Array 2D-dimensional ausgeben
    for (int y=0; y<HOEHE; y++)
    {
        for (int x=0; x<BREITE; x++)
        {
            printf("A[%d][%d]=%03d  ", y,x, A[y][x]);            
        }
        printf("\n");
    }

}