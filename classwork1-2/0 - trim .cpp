#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    int start = 0, end = n - 1;

    while(start < n && v[start] == 0)
        ++start;

    while(end + 1 > 0 && v[end] == 0)
        --end;

    for(int i = start; i <= end; ++i)
        std::cout << v[i] << " ";
}