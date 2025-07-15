#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[1000002];
int EA[1000002][2];
bool vis[1000002] = {};

void dfs(int cur)
{
    vis[cur] = 1;
    EA[cur][0] = 0;
    EA[cur][1] = 1;

    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;

        dfs(nxt);
        EA[cur][0] += EA[nxt][1];
        EA[cur][1] += min(EA[nxt][0], EA[nxt][1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << min(EA[1][0], EA[1][1]);
}