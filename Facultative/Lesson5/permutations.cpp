#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    
    while(n > 9)
    {
        v.push_back(n%10);
        n /= 10;
    }
    v.push_back(n);
    sort(v.begin(), v.end());

    do
    {   
       long long num = accumulate(v.begin(), v.end(), 0, [](int a, int b){return a*10 + b;});
       cout << num << " " << num * num << endl;  
    }while(next_permutation(v.begin(), v.end()));
}
