#include <iostream>
#include <map>
#include <string>

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment << ":\n";
    
    for (const auto& [key, value] : m)
        std::cout << '[' << key << "] = " << value << "; ";

    std::cout << "\n";
}

int main()
{
    std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    m["SSD"] = 30; // insert a new key-value pair {"SSD", 30}
    print_map("Aktueller Stand der Map", m);

    m.erase("GPU");
    print_map("Aktueller Stand der Map", m);

    std::map<std::string, std::string> kunde;
    kunde["Vorname"]  = "Jürgen";
    kunde["Nachname"] = "Brauer";
    kunde["Wohnort"]  = "New York";
    kunde["PLZ"]      = "109283";
    std::cout << kunde["Vorname"] << " " << kunde["Nachname"] << "\n"
              << kunde["PLZ"]     << " " << kunde["Wohnort"] << "\n";
}