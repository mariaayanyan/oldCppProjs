#include <iostream>
using namespace std;

int binpow(int a, int n)
{
    if(n == 0)
        return 1;
    if(n&1)
        return a*binpow(a,n-1);
    int pow = binpow(a, n/2);
    return pow*pow;
}

int main()
{
    int a, n;
    cin >> a >> n;
    cout << binpow(a, n);
}