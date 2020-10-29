#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v = {13, 23, 21, 0, 23, 14, 0, 15, 0, 23, 0};
    auto it1 = max_element(v.begin(), v.end());
    auto it2 = max_element(v.rbegin(), v.rend()).base();
    int answer = count(it1+1, it2, 0);  

    cout << answer << endl;
}