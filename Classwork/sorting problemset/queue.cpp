#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void sort(std::vector<std::pair<int,int>> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i].first > v[j].first)
                std::swap(v[i],v[j]);
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int,int>> v(n);

    for(int i = 0; i < n; ++i)
    {
        std::cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v);

    for(int i = 0; i < n; ++i)
        std::cout << v[i].second << " ";

}

