#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>  // std::out_of_range

void foo(int* ptrArray, int size)
{
    std::cout << "First element is " << *ptrArray << "\n";
}


int main()
{
    std::vector<int> v1 = {-1, 3, 5, -8, 0};
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(20);

    v1.insert(v1.begin(), -100);
    

    std::vector<int> v2;    
    auto v3(v1);

    std::cout << "v1.front() is the first element: " << v1.front() << std::endl;
    std::cout << "v1.back() is the last element: "   << v1.back()  << std::endl;
    std::cout << "v1[2]: "    << v1[2]    << std::endl;
    std::cout << "v1.at(2): " << v1.at(2) << std::endl;

    try {
        //auto b = v1.at(10);
        auto b = v1[10];
        std::cout << "v1[10]=" << b << "\n";
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of Range error wurde gefangen!\n";
        std::cerr << "Fehlertext ist:\n" << oor.what() << "\n";
    }


    std::vector <std::string> friends;

    friends.push_back("Ali");
    friends.push_back("Kemal");
    friends.push_back("Akin");
    friends.push_back("Veli");
    friends.push_back("Hakan");
        
    // finding middle using size() / 2
    int middleIndexRef = friends.size() / 2;

    friends.insert(friends.begin() + middleIndexRef, "Bob");

    for(int j = 0; j < friends.size(); j++)
    {
        std::cout << "Friend #" << j << " : " << friends.at(j) << "\n";
    }   

    for (const auto & f : friends)
    {
        std::cout << f << " ";
    }

}