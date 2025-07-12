#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100002];
int vis[100002] = {};

void dfs(int cur)
{
    if(vis[cur]) return;
    vis[cur] = 1;
    
    for(auto nxt : adj[cur])
        dfs(nxt);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }

    cout << 2*cnt + m - n - 1;
}