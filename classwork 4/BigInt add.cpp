#include <iostream>
#include <string>
#include <algorithm>

std::string BigIntAdd(std::string a, std::string b)
{
    std::string ans;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int len = std::max(a.length(),b.length());
    a.resize(len, '0');
    b.resize(len, '0');

    int carry = 0;

    for(int i = 0; i < len; ++i)
    {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        carry = sum/10;
        sum = sum%10;
        ans += char('0' + sum);
    }

    if(carry)
        ans += char('0' + carry);

    reverse(ans.begin(), ans.end());

    return ans;
}
int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::string ans = BigIntAdd(a, b);
    std::cout << ans;

}