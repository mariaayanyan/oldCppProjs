#include <iostream>
#include <string>

char BigIntCompare(std::string const&a, std::string const &b)
{
    if(a.length() != b.length())
        return a.length() < b.length() ? '<' : '>';

    for(int i = 0; i < a.length(); ++i)
    {
        if(a[i] != b[i])
            return a[i] < b[i] ? '<' : '>';
    }

    return '=';
}
int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::cout << BigIntCompare(a,b);
}