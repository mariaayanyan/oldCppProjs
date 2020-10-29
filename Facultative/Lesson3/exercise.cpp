#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if(n == 2)
        return true;
    if(n == 1 || n%2 == 0)
        return false;
    
    for(int i = 3; i*i <= n; i += 2)
        if(n%i == 0)
            return false;

    return true;
}

bool twoDgts(int n)
{
    return n/100 == 0 && n/10;
}

bool isEven(int n)
{
    return !(n%2);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    v.erase(remove_if(v.begin(), v.end(), isPrime), v.end());

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;

    auto it = find_if(v.begin(), v.end(), twoDgts);
    if(it == v.end())
        cout << "None found\n";
    else
    {
        cout << *it << endl;
    }

    cout << count_if(max_element(v.begin(), v.end()) + 1, v.end(), isEven) << endl;   
}