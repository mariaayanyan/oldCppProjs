#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    if(n==0)
    {
        std::cout << 0;
        return 0;
    }

    std::vector<int>digits;
    while(n!=0)
    {
        digits.push_back(n%10);
        n/=10;
    }

    for(int i = digits.size()-1; i + 1 > 0; --i)
        std::cout<<digits[i]<<" ";



}