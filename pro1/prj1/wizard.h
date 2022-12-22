#include "warrior.h"

class wizard : public warrior
{
    public:

    wizard(std::string name) : warrior(name)
    {
        std::cout << "Erzeuge eine neuen Zauberer mit Namen " << name << "\n";
    }

    wizard() : warrior("Zauberer")
    {
        std::cout << "Default Konstruktur von wizard aufgerufen\n";
    }

    ~wizard()
    {
        std::cout << "Das war's dann wohl mit mir (" << name << ")\n";
    }

    void kaempfe()
    {
        std::cout << name << " zaubert\n";
    }
};