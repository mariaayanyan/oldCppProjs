#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;
int main()
{
    set<string> st;
    string s;

    freopen("input.txt", "r", stdin);

    while(cin >> s) 
    {
        transform(s.begin(), s.end(), s.begin(), [](char c){return tolower(c);});
        if(ispunct(s.back()))
            s.pop_back();
        st.insert(s);
    }
    cout << st.size() << endl;
}