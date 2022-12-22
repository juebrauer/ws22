#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

#include "wizard.h" // --> class wizard
#include "archer.h" // --> class archer


int main()
{
    //warrior* r1 = new warrior("Aragon");

    warrior* enemies[] = { new wizard("Gandalf3"), new archer("Robin Hood2") };

    enemies[0]->kaempfe();

    //int A[50];
    //wizard wizards[] = { wizard("Gandalf1"), wizard("Gandalf2") };

    wizard* w1 = new wizard("Dumbeldore");
    archer* a1 = new archer("Robin Hood");

    std::vector<warrior*> alle_einheiten;
    //alle_einheiten.push_back( r1 );
    alle_einheiten.push_back( w1 );
    alle_einheiten.push_back( a1 );

    for (int i=0; i<5; i++)
    {
        for (int einheit_nr=0; einheit_nr<alle_einheiten.size(); einheit_nr++)
        {
            alle_einheiten[einheit_nr]->kaempfe();
        }
    }

    for (int einheit_nr=0; einheit_nr<alle_einheiten.size(); einheit_nr++)
    {
        delete (alle_einheiten[einheit_nr]);
    }
 
}