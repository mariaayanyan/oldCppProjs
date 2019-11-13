#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

vector<int> st(1000000, 50000);
vector<int> a;

int init(int v = 1, int i = 0, int j = a.size()) {
    if(j - i == 1) {
        return st[v] = a[i];
    }

    int md = (i + j) / 2;
    return st[v] = min(init(v * 2, i , md), init(v * 2 + 1, md, j));
}

int get(int l, int r, int v = 1, int i = 0, int j = a.size()) {
    if(l <= i && j <= r) {
        return st[v];
    }

    if(r <= i || l >= j) {
        return 50000;
    }

    int md = (i + j) / 2;
    return min(get(l, r, 2 * v, i, md), get(l, r, 2 * v + 1, md, j));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init();
    for(int i = 0; i <= n - k; ++i) {
        cout << get(i, i + k) << " ";
    }
    cout << endl;
}