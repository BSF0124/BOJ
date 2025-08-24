#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
long long c, mn = 1, mx;
vector<pair<long long,int>> adj[100002];
long long d[100002];

bool func(long long lim)
{
    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    pq.push({0, st});
    while(!pq.empty())
    {
        auto [w, u] = pq.top(); pq.pop();
        if(d[u] != w) continue;
        for(auto [dw, v] : adj[u])
        {
            if(dw > lim) continue;
            dw += w;
            if(dw >= d[v]) continue;
            d[v] = dw;
            pq.push({dw, v});
        }
    }

    return d[en] <= c;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st >> en >> c;
    while(m--)
    {
        int u, v;
        long long t;
        cin >> u >> v >> t;
        adj[u].push_back({t,v});
        adj[v].push_back({t,u});
        mx = max(mx, t);
    }

    while(mn < mx)
    {
        long long mid = (mn+mx) / 2;
        if(func(mid)) mx = mid;
        else mn = mid+1;
    }

    if(func(mn)) cout << mn;
    else cout << -1;
}