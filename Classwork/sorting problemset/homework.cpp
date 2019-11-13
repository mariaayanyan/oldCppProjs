#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    int mn, mx;

    std::cin >> mn;
    mx = mn;

    for(int i = 1; i < n; ++i)
    {
        int temp;
        std::cin >> temp;
        mx = std::max(mx, temp);
        mn = std::min(mn, temp);
    }

    std::cout << mn*mx;
}