#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool pred(int a, int b)
{
    return b == 2*a;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v1(n), v2(n);

    for(int i = 0; i < n; ++i)  
        cin >> v1[i];
    for(int i = 0; i < n; ++i)
        cin >> v2[i];


    cout << *mismatch(v1.begin(), v1.end(), v2.begin(), pred).second << endl;

    
    
}