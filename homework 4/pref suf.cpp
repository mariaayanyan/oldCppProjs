#include <iostream>
#include <string>
bool is_pref(std::string const &a, std::string const &b)
{
    for(int i = 0; i < b.length(); ++i)
        if(a[i] != b[i])
            return false;

        return true;
}
bool is_suff(std::string const &a, std::string const &b)
{
    int ind = a.length() - b.length();

    for(int i = 0; i < b.length(); ++i)
        if(a[ind + i] != b[i])
            return false;

        return true;
}

int main()
{
    std::string S, s;
    std::cin >> S >> s;

    if(S.length() < s.length())
    {
        std::cout << "Neither";
        return 0;
    }
    bool prefix = false, suffix = false;

    prefix = is_pref(S, s);
    suffix = is_suff(S, s);

    if(prefix && suffix)
        std::cout << "Both";
    else if(prefix)
        std::cout << "Prefix";
    else if(suffix)
        std::cout << "Suffix";
    else
        std::cout << "Neither";

}