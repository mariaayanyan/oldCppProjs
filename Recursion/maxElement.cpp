#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxElement(const vector<int>& vec, int first, int last)
{
    if(last == first || last == first + 1)
        return max(vec[first], vec[last]);

    return max({vec[first], vec[last], maxElement(vec, first+1, last-1)});
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    int Q;
    cin >> Q;

    for(int q = 0; q < Q; ++q)
    {
        int first, last;
        cin >> first >> last;
        cout << maxElement(v, first, last) << endl;
    }

}
