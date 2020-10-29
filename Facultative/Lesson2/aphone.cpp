#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    deque<string> dq;

    for(int i = 0; i < n; ++i)
    {
        string num;
        cin >> num;

        auto it = find(dq.begin(), dq.end(), num);
        if(it != dq.end())
        {
            dq.erase(it);
            dq.push_back(num);
            continue;
        }
        dq.push_back(num);
        if(dq.size() > m)
            dq.pop_front();
    }

    for(int i = (int)dq.size() - 1; i >= 0; --i)
        cout << dq[i] << endl;
    for(int i = dq.size(); i < m; ++i)
        cout << "<Empty>" << endl;

}
