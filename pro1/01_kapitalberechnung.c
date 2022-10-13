#include <stdio.h>
int main()
{       
    char weiter;
    do
    {
        float startkapital;
        
        printf("\nDein Startkapital: ");
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

        printf("\nWillst du eine weitere Kapitalverzinsung"
            "berechnen? (j/n)");
       
        
        scanf(" %c", &weiter);
        printf("Du hast folgendes Zeichen eingegeben: %c", weiter);

            

    } while (weiter=='j');

    return 0;
}


