#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<double> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] < v[j])
                std::swap(v[i],v[j]);
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<double> v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    sort(v);

    m = std::min(m, n);
    double sum = 0;

    for(int i = 0; i < m; ++i)
        sum += v[i];

    std::cout << sum;

}