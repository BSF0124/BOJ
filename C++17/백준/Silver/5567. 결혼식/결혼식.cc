#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> adj[502];
int dist[502];

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
    dist[1] = 1;

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if(dist[cur] > 2) continue;
        
        for(auto nxt : adj[cur])
        {
            if(dist[nxt] > 0) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
            ans++;
        }
    }

    cout << ans;
}
