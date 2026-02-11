#include <bits/stdc++.h> 
using namespace std;

int n, m, st;
vector<int> adj[1002];
bool vis[1002];

void bfs()
{
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }
}

void dfs(int cur)
{
    vis[cur] = 1;
    cout << cur << ' ';
    for(auto nxt : adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(st);
    fill(vis, vis+1002, 0);
    cout << '\n';
    bfs();
}