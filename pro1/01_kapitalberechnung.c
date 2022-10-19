#include <stdio.h>



void berechne_kapital_entwicklung(  float startkapital,
                                    float zielkapital,
                                    float zinsrate )
{
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
}

int main()
{       
    char weiter;
    do
    {            
        float startkapital;
        float zielkapital;
        float zinsrate;

        printf("\nDein Startkapital: ");
        scanf("%f", &startkapital);
      
        printf("Dein Zielkapital: ");
        scanf("%f", &zielkapital);
      
        printf("Dein Zinssatz: ");
        scanf("%f", &zinsrate);

        berechne_kapital_entwicklung(startkapital, zielkapital, zinsrate);

        printf("\nWillst du eine weitere Kapitalverzinsung"
            "berechnen? (j/n)");       
        
        scanf(" %c", &weiter);
        printf("Du hast folgendes Zeichen eingegeben: %c", weiter);
           

    } while (weiter=='j');

    return 0;
}


