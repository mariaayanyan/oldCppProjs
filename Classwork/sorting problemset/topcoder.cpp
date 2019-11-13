#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <iomanip>
using namespace std;

void sort(std::vector<pair<double, string>> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] < v[j])
                std::swap(v[i],v[j]);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<double, string>> v(n);

    for(int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;

    int m;
    cin >> m;

    v.resize(n+m);
    for(int i = 0; i < m; ++i)
        cin >> v[n+i].first >> v[n+i].second;

    sort(v);

    cout << fixed << setprecision(2);

    cout << n+m << endl;

    for(auto el : v)
        cout << el.first << " " << el.second << endl;

}