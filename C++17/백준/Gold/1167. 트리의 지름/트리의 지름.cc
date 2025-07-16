#include <bits/stdc++.h>
using namespace std;

int n, mx = 0, node = 0;
vector<pair<int,int>> adj[100002];
bool vis[100002];

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
    for(int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;

        while(1)
        {
            int v, w;
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back({v,w});
        }
    }

    fill(vis, vis+n+1, 0);
    dfs(1, 0);

    fill(vis, vis+n+1, 0);
    mx = 0;
    dfs(node, 0);

    cout << mx;
}