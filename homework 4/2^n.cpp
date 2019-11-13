#include <iostream>
#include <vector>

void Double(std::vector<int>& num)
{
    int carry = 0;
    for(int i = 0; i < num.size(); ++i)
    {
        num[i] = 2*num[i] + carry;
        carry = num[i]/10;
        num[i]%=10;
    }
    if(carry)
        num.push_back(carry);
}
int main()
{
    int n;
    std::cin >> n;

    std::vector<int>ans = {1};

    for(int i = 0; i < n; ++i)
        Double(ans);

    for(int i = ans.size()-1; i >=0; --i)
        std::cout << ans[i];
}