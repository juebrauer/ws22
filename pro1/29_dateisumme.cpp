#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string dateiname="zahlen.txt";
    
    ifstream inFile;    
    inFile.open( dateiname );
    if (!inFile) {
        cout << "Unable to open file: " << dateiname << "\n";
        exit(1); // terminate with error
    }

    string token;
    int sum = 0;
    while (true)
    {
        inFile >> token;
        cout << token << " ";

        

        sum = sum + zahl;
    }

    cout << "Summe ist " << sum << "\n";

    inFile.close();



}