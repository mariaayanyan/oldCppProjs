#include <iostream>
#include <string>
#include <cctype>
bool is_end(char a)
{
    return a == '.' || a == '!' || a == '?';
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    bool end = true, new_word = true;
    int mistake_count = 0;

    std::string txt;

    while(getline(std::cin, txt))
    {
        new_word = true;
        for (char c : txt)
        {
            if (isspace(c) || isdigit(c))
            {
                new_word = true;
                continue;
            }

            if (ispunct(c))
            {
                if (!end)
                    end = is_end(c);
                new_word = true;
                continue;
            }

            if (end)
            {
                if (islower(c))
                    ++mistake_count;
                end = false;
                new_word = false;
                continue;
            }

            if (isupper(c) && !new_word)
                ++mistake_count;

            new_word = false;
        }
    }
    std::cout << mistake_count;
}