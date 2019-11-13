#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<double>a(n);

    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    int m;
    std::cin >> m;

    double sum=0;

    for(int i = 0; i < m; ++i)
    {
        int ind;
        std::cin >> ind;

        sum += a[ind];
    }

    std::cout << sum;

    return 0;
}