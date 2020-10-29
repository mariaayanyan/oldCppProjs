#include <iostream>
#include <set>
using namespace std;
int main()
{
    multiset<int> st;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int el;
        cin >> el;
        st.insert(el);
    }
    
    for(auto el : st)
        cout << el << " ";
    cout << endl;
}