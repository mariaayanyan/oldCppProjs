#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tll;
#define sq(x) (x)*(x)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;

    while(z--)
    {
        int n;
        cin >> n;

        multiset<tll>events;

        for(int i = 0; i < n; ++i)
        {
            ll r, s;
            cin >> r >> s;

            tll tmp1(max(0ll, i-r), -1, s);
            tll tmp2(min(ll(n-1), i+r), 1, s);

            events.insert(tmp1);
            events.insert(tmp2);
        }

        ll q = 0, ans = 0;
        multiset<ll>st;
        for(const auto& el: events)
        {
            ll ind, type, val;
            tie(ind, type, val) = el;

            if(type == -1)
            {
                ++q;
                st.insert(-val);

                if(q >= 3)
                {
                    ll sum = 0;
                    auto it = st.begin();
                    for(int i = 0; i < 3; ++i)
                    {
                        sum -= *it;
                        it++;
                    }
                    ans = max(ans, sum);
                }

                continue;
            }

            auto it = st.find(-val);
            if(it!=st.end())
            {
                st.erase(it);
                --q;
            }
        }

        cout << ans << endl;
    }

}
