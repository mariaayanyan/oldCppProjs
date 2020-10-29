#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string vowels = "aieouy";
bool pred(const string& a, const string& b)
{
    auto it1 = find_first_of(a.rbegin(), a.rend(), vowels.begin(), vowels.end());
    auto it2 = find_first_of(b.rbegin(), b.rend(), vowels.begin(), vowels.end());
    return(it1 != a.rbegin() && it2 != b.rbegin() && *it1 == *it2);
}
int main()
{
    vector<string> v;
    string s;
    while(getline(cin, s))
    {
        v.push_back(s);
    }

    for(auto it = v.begin(); it != v.end() - 1; ++it)
    {
        if(adjacent_find(it, v.end(), pred) != it)
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
