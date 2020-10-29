#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v;
    istream_iterator<int> it(cin);
    copy_n(it, n, back_inserter(v));

    for(int i = 0; i < n; ++i)
        cout << v[i] << " ";

}