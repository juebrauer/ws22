#include "warrior.h"

class archer : public warrior
{
    public:

    archer(std::string name) : warrior(name)
    {
        std::cout << "Ein neuer Bogenschütze mit Namen " << name << " wurde geboren!\n";
    }


    ~archer()
    {
        std::cout << "Das war's dann wohl mit dem Bogenschützen (" << name << ")\n";
    }

    void kaempfe()
    {
        std::cout << name << " schießt Pfeile\n";
    }
};