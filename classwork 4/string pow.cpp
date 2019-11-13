#include <iostream>
#include <string>

void pow(std::string const&s, int p)
{
    if(p >= 0)
    {
        for(int i = 0; i < p; ++i)
            std::cout << s;

        return;
    }

    p = -p;

    if(s.length() % p)
    {
        std::cout << "undefined";
        return;
    }

    std::string ans = s.substr(0, s.length()/p);


    for(int i = ans.length(); i < s.length(); i+= ans.length())
    {
        for(int j = 0; j < ans.length(); ++j)
        {
            if(s[i+j] != ans[j])
            {
                std::cout << "undefined";
                return;
            }
        }
    }

    std::cout << ans;

}
int main()
{
    std::string s;
    int p;

    std::cin >> s >> p;

    pow(s,p);

}
