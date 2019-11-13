#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int state = 0, unsolved = 0;

    for(int i = 0; i < n; ++i)
    {
        int event;
        std::cin >> event;

        if(event < 0 && state == 0)
            ++unsolved;
        else
            state += event;
    }

    std::cout << unsolved;
}