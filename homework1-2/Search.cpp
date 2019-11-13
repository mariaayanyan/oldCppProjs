#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    int num;
    std::cin >> num;

    bool found=false;

    for(int i = n-1; i+1 > 0; --i)
    {
        if(v[i] == num)
        {
            std::cout << i+1 << " ";
            found = true;
        }
    }

    if(!found)
        std::cout << -1;
}