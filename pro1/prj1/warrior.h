#ifndef _WARRIOR_H
#define _WARRIOR_H

class warrior
{
    public:

    // Konstruktor der Klasse warrior
    warrior(std::string name)
    {
        this->x = 0;
        this->y = 0;
        this->energy = 1.0;
        this->name = name;
    }

    virtual ~warrior()
    {
        std::cout << "Lösche Objekt\n";
    }

    // Eine weitere Methode
    void zeige_infos()
    {
        std::cout << name << " ist an (" << x << "," << y << ") und hat"
                  << " Restenergie "
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

    virtual void kaempfe()
    {
        std::cout << name << " kaempft!\n";
    };


    protected:
    
    int x;
    int y;
    float energy;
    std::string name;
};

#endif