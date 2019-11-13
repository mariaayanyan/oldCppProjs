#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::string s;
    std::cin >> s;

    std::stack<char>seq;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '(')
            seq.push(s[i]);

        else if(seq.empty())
        {
            std::cout << "No\n";
            return 0;
        }
        else
            seq.pop();
    }

    std::cout << (seq.empty() ? "Yes\n" : "No\n");
}