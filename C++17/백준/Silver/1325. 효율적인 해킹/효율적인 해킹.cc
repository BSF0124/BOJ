#include <bits/stdc++.h>
using namespace std;

int n, m, mx = 0;
vector<int> adj[10002];
int computer[10002] = {};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        queue<int> q;
        q.push(i);
        bool vis[n+1] = {};
        vis[i] = 1;

        int cnt = 0;
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            cnt++;
            for(auto nxt : adj[cur])
            {
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = 1;
            }
        }
        mx = max(mx, cnt);
        computer[i] = cnt;
    }

    for(int i = 1; i <= n; i++)
        if(computer[i] == mx) cout << i << ' ';
}