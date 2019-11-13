#include <iostream>
#include <vector>
#include <algorithm>

void sort(std::vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] < v[j])
                std::swap(v[i],v[j]);
}
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    sort(v);

    std::vector<std::vector<int>>ans(2);

    for(int i = 0; i < n; ++i)
        ans[i%2].push_back(v[i]);

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < ans[i].size(); ++j)
            std::cout << ans[i][j] << " ";
        std::cout << '\n';
    }

}
