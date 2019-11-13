#include <iostream>
#include <vector>


int main()
{
    int n;
    std::cin >> n;

    std::vector<int>v(n);
    int ans = 0, cur = 1;

    for(int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    for(int i = 1; i < n; ++i)
    {
        if(v[i] > v[i-1])
        {
            ++cur;
            continue;
        }

        if(cur > ans)
            ans = cur;

        cur = 1;
    }

    if(cur > ans)
        ans = cur;


    std::cout << ans;

}