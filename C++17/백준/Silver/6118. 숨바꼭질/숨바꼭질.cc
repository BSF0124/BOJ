#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0, mx = 0, cnt = 0;
vector<int> adj[20002];
int dist[20002] = {};

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

    queue<int> q;
    q.push(1);
    fill(dist, dist+n+1, -1);
    dist[1] = 0;

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur])
        {
            if(dist[nxt] > -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
        mx = max(mx, dist[cur]);
    }

    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == mx)
        {
            cnt++;
            if(ans == 0) ans = i;
        }
    }

    cout << ans << ' ' << mx << ' ' << cnt;
}