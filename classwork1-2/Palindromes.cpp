#include <iostream>
#include <vector>

bool is_palindrome(const std::vector<char>&v)
{
    for(int i = 0; i < v.size()/2; ++i)
        if(v[i] != v[v.size()-i-1])
            return false;

        return true;
}
char to_lowercase(char a)
{
    return ('a' <= a && a <= 'z' ? a : char(a - 'A' + 'a'));
}
int main()
{
    int len;
    std::cin >> len;

    std::vector<char>name(len);

    for(int i = 0; i < len; ++i)
    {
        std::cin>>name[i];
        name[i]=to_lowercase(name[i]);
    }

    std::cout << (is_palindrome(name) ? "yes" : "no");
}