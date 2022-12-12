#include <stdlib.h>

#include <iostream>

class warrior
{
    public:

    // Konstruktor der Klasse warrior
    warrior()
    {
        x = 0;
        y = 0;
        energy = 1.0;
    }

    // Eine weitere Methode
    void zeige_infos()
    {
        std::cout << "Ich bin an (" << x << "," << y << ") und habe Restenergie "
                  << energy << "\n"; 
    }

    // Eine weitere Methode (Methoden sind Funktionen in Klassen)
    void laufe_zur_stelle(int neue_posx, int neue_posy)
    {
        if (energy >= 0.1)
        {
            x = neue_posx;
            y = neue_posy;
            energy -= 0.1;
        }
        else
        {
            std::cout << "Sorry! Bin zu müde! Keine Energie mehr!\n";
        }
    }

    void mache_eine_pause(float stunden)
    {
        std::cout << "Ich mach mal ein Päusschen von " << stunden << " Stunde(n).\n";
        energy += stunden*0.1;
    }

    private:
    
    int x;
    int y;
    float energy;
};

int main()
{
    warrior* w1 = new warrior();

    w1->zeige_infos();

    for (int i=1; i<=15; i++)
    {
        w1->laufe_zur_stelle(i,i);
        if (rand() % 3 == 0)
            w1->mache_eine_pause(1.0);
        w1->zeige_infos();
    }

 
}