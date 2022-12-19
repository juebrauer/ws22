#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

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

    virtual void kaempfe() = 0;


    protected:
    
    int x;
    int y;
    float energy;
    std::string name;
};

class wizard : public warrior
{
    public:

    wizard(std::string name) : warrior(name)
    {

    }

    void kaempfe()
    {
        std::cout << name << " zaubert\n";
    }
};

class archer : public warrior
{
    public:

    archer(std::string name) : warrior(name)
    {

    }

    void kaempfe()
    {
        std::cout << name << " schießt Pfeile\n";
    }
};



int main()
{
    //warrior* r1 = new warrior("Aragon");

    wizard* w1 = new wizard("Dumbeldore");
    archer* a1 = new archer("Robin Hood");

    std::vector<warrior*> alle_einheiten;
     alle_einheiten.push_back( w1 );
    alle_einheiten.push_back( a1 );

    for (int i=0; i<5; i++)
    {
        for (int einheit_nr=0; einheit_nr<alle_einheiten.size(); einheit_nr++)
        {
            alle_einheiten[einheit_nr]->kaempfe();
        }
    }
 
}