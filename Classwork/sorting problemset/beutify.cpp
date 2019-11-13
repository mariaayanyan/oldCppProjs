#include <iostream>
#include <vector>

void sort(std::vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] > v[j])
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

    for(int i = 0; i < n; i+=2)
        std::cout << v[i] << " ";

    for(int i = n-1 - (n&1); i >=0; i-=2)
        std::cout << v[i] << " ";

}