#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, ans;
vector<pair<int,int>> adj[1002];

void dfs(int cur, int par)
{
    for(auto nxt : adj[cur])
    {
        if(par == nxt.first) continue;
        
        ans += nxt.second;
        
        if(v == nxt.first) cout << ans << '\n';
        
        dfs(nxt.first, cur);
        ans -= nxt.second; 
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(--n)
    {
        int d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    while(m--)
    {
        cin >> u >> v;
        ans = 0;
        dfs(u, 0);
    }
}