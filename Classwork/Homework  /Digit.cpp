#include <iostream>
#include <string>
#include <fstream>

int main()
{
    int n;
    std::cin >> n;

    std::ifstream in("number.txt");
    if(!in.is_open())
    {
        std::cout << "Error\n";
        in.close();
        return 0;
    }

    std::string s;
    in >> s;
    in.close();

    std::cout << s[n-1];
}