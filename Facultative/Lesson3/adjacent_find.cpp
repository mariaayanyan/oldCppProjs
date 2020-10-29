#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool pred(int a, int b)
{
    return b == 2*a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    auto it = adjacent_find(v.begin(), v.end(), pred);
    if(it == v.end())
        cout << "No\n";
    else
    {
        cout << *(it++) << " " << *it << endl; 
    }
    

}