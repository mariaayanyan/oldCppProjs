#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int>val(n), dp(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> val[i];
    }

    dp[0] = val[0];
    dp[1] = max(val[1], val[0] + val[1]);

    for(int i = 2; i < n; ++i)
    {
        dp[i] = val[i] + max(dp[i-1],dp[i-2]);
    }

    int last = dp[n-1];
    cout << last << endl;

    last-= val[n-1];

    vector<int>ans;
    ans.push_back(n);

    for(int i = n-2; i >=0; --i)
    {
        if(dp[i] == last)
        {
            ans.push_back(i+1);
            last-= val[i];
        }
    }

    for(int i = ans.size()-1; i>=0; --i)
        cout << ans[i] << " ";

}