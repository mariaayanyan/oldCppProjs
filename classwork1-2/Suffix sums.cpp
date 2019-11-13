#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<double>v(n);

    double sum=0;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
        sum+=v[i];
    }

    for(int i = 0; i < n; ++i)
    {
        std::cout << sum << " ";
        sum-=v[i];
    }


}



