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


void benutzer_eingabe(float* ptr_startkapital,
                       float* ptr_zielkapital,
                       float* ptr_zinsrate)
{
    printf("\nDein Startkapital: ");
    scanf("%f", ptr_startkapital);
    
    printf("Dein Zielkapital: ");
    scanf("%f", ptr_zielkapital);
    
    printf("Dein Zinssatz: ");
    scanf("%f", ptr_zinsrate);  
}

int main()
{       
    char weiter;
    do
    {            
        float startkapital;
        float zielkapital;
        float zinsrate;

        // Call-by-reference
        benutzer_eingabe(&startkapital,
                         &zielkapital,
                         &zinsrate);
   
        // Call-by-value
        berechne_kapital_entwicklung(startkapital, zielkapital, zinsrate);

        printf("\nWillst du eine weitere Kapitalverzinsung"
            "berechnen? (j/n)");       
        
        scanf(" %c", &weiter);
        printf("Du hast folgendes Zeichen eingegeben: %c", weiter);          

    } while (weiter=='j');

    return 0;
}


