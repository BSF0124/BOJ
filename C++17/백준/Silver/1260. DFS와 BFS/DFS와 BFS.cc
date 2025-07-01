#include <bits/stdc++.h>
using namespace std;

int n, m, v;
vector<int> adj[1002];
bool vis[1002] = {};

void bfs()
{
    queue<int> q;
    q.push(v);
    vis[v] = 1;

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
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

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> v;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    dfs(v);
    fill(vis, vis+1002, 0);
    cout << '\n';
    bfs();
}
