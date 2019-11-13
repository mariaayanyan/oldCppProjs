#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int>veryBadBucket(2000);

    for(int i = 0; i < n; ++i)
    {
        int temp;
        std::cin >> temp;
        ++veryBadBucket[temp+1000];
    }

    int m;
    std::cin >> m;

    for(int i = 0; i < m; ++i)
    {
        int temp;
        std::cin >> temp;

        if(veryBadBucket[temp+1000])
            std::cout << temp << " ";
    }

}