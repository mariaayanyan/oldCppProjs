#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int>v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    k%= n;
    k = n - k;
    for(int i = 0; i < n; ++i)
        std::cout << v[(k+i)%n] << " ";
}