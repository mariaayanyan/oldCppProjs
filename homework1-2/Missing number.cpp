#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    int sum = (n+1)*n/2;
    int cur_sum=0;

    for(int i = 0; i < n-1; ++i)
    {
        int temp;
        std::cin >> temp;
        cur_sum += temp;
    }

    std::cout << sum - cur_sum;

}