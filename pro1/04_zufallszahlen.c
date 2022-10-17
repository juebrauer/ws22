#include <stdio.h>  // printf()
#include <stdlib.h> // rand()
#include <time.h>

int main()
{
    int startwert = time(NULL);
    //printf("startwert = %d\n", startwert);
    srand( startwert );

    int zufallszahl;
    for (int i=1; i<=50; i++)
    {
        zufallszahl = (rand() % 6) + 1;
        printf("%d ", zufallszahl);
    }

    printf("\n");
}