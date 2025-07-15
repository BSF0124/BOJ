#include <bits/stdc++.h>
using namespace std;

int n, mx = 0, node = 0;
vector<pair<int,int>> adj[10002];
bool vis[10002];

void dfs(int cur, int dist)
{
    vis[cur] = 1;

    if(dist > mx)
    {
        mx = dist;
        node = cur;
    }

    for(auto nxt : adj[cur])
    {
        if(vis[nxt.first]) continue;
        dfs(nxt.first, dist + nxt.second);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    fill(vis, vis+n+1, 0);
    dfs(1, 0);

    fill(vis, vis+n+1, 0);
    mx = 0;
    dfs(node, 0);

    cout << mx;
}