#include <iostream>
#include <string>

int main()
{
    int x, y, n;
    std::cin >> x >> y >> n;

    for(int i = 0; i < n; ++i)
    {
        std::string dir;
        std::cin >> dir;

        if(dir == "up")
        {
            ++y;
            continue;
        }
        if(dir == "down")
        {
            --y;
            continue;
        }
        if(dir == "left")
        {
            --x;
            continue;
        }
        if(dir == "right")
        {
            ++x;
        }

    }

    std::cout << x << " " << y;
}