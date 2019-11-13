//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const ll INF = 1LL << 60;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>>adj(n);
    vector<int>parent(n), processed(n); vector<ll> dist(n, INF);

    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >>  b >> w;

        adj[a-1].emplace_back(w, b-1);
        adj[b-1].emplace_back(w, a-1);

    }

    priority_queue<pii> q;
    parent[0] = -1;

    dist[0] = 0;
    q.push({0, 0});

    while(!q.empty())
    {
        int a = q.top().second;
        q.pop();

        if(processed[a])
            continue;
        processed[a] = 1;

        for(auto pp : adj[a])
        {
            int w, b;
            tie(w, b) = pp;

            if(dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
                parent[b] = a;
            }

        }

    }

    if(dist[n-1] == INF)
    {
        cout << -1;
        return 0;
    }

    vector<int>path;

    int ind = n-1;
    path.push_back(n);

    while(parent[ind] != -1)
    {
        ind = parent[ind];
        path.push_back(ind+1);

    }

    for(int i = path.size() - 1; i >= 0; --i)
        cout << path[i] << " ";

}
