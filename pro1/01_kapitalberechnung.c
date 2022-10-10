#include <stdio.h>

// Das ist ein kleines Programm,
// in dem wir die ersten C-Schritte lernen


int main()
{
    float startkapital;
    printf("Dein Startkapital: ");
    scanf("%f", &startkapital);

    float zielkapital;
    printf("Dein Zielkapital: ");
    scanf("%f", &zielkapital);

    float zinsrate;
    printf("Dein Zinssatz: ");
    scanf("%f", &zinsrate);

    int jahr;
    jahr = 0;

    float kapital;
    kapital = startkapital;
    while (kapital<zielkapital)
    {
        kapital = kapital * (1+zinsrate/100);
        jahr = jahr + 1;
        printf("\nNach %d Jahr hast du: %f", jahr, kapital);
    }

    return 0;
    
}
