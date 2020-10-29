#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    ostream_iterator<int> it(cout, ", ");
    copy_if(v.begin(), v.end(), it, [](int a){return a%2 == 0;});
}