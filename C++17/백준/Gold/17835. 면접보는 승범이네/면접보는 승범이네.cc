#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x7f7f7f7f7f7f;
int n, m, k;
vector<pair<long long,int>> adj[100002];
long long d[100002];
priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    fill(d+1, d+n+1, INF);

    while(m--)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[v].push_back({c,u});
    }

    while(k--)
    {
        int st;
        cin >> st;
        d[st] = 0;
        pq.push({0, st});
    }
    
    while(!pq.empty())
    {
        auto [w, u] = pq.top(); pq.pop();
        if(d[u] != w) continue;
        for(auto nxt : adj[u])
        {
            auto [dw, v] = nxt;
            dw += w;
            if(dw >= d[v]) continue;
            d[v] = dw;
            pq.push({dw, v});
        }
    }

    int ans = max_element(d+1, d+n+1) - d;
    cout << ans << '\n' << d[ans];
}