#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[102];
bool vis[102] = {};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            ans++;
        }
    }
    cout << ans;
}
