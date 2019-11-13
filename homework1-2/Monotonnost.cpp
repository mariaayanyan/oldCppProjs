

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>v(n);

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    bool asc = true, desc = true;

    for(int i = 1; i < n && (asc || desc); ++i)
    {
        if(v[i-1] <= v[i])
            desc=false;
        if(v[i] <= v[i-1])
            asc = false;
    }

    if(!desc && !asc)
        std::cout << "Neither";
    else
        std::cout << (asc ? "Аscending" : "Descending");

}