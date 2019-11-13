#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    for(int i = 0; i < n; ++i)
    {
        int count = 0, num = v[i];

        while(i < n && v[i] == num)
        {
            ++i; ++count;
        }

        if(i < n) --i;
        std::cout << count << " times " << num << '\n';

    }

}