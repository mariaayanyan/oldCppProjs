#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];

    for(int step = 1; ; ++step)
    {
        auto it = adjacent_find(v.begin(), v.end());
        cout << "Step " << step << ": ";
        for(int i = 0; i < v.size(); ++i)
            cout << v[i] << " ";
        cout << endl;

        if(it == v.end())
            break;
        v.erase(it, it+2);
    }
    
}