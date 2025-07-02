#include <bits/stdc++.h>
using namespace std;

int n, m, ans, mn = INT_MAX;
vector<int> adj[5002];

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

    for(int i = 1; i <= n; i++)
    {
        queue<int> q;
        int dist[n+1] = {};

        q.push(i);
        fill(dist, dist+n+1, -1);
        dist[i] = 0;

        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur])
            {
                if(dist[nxt] > -1) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }

        int sum = 0;
        for(int j = 1; j <= n; j++)
            if(i != j) sum += dist[j];
        if(mn > sum)
        {
            mn = sum;
            ans = i;
        }
    }
    cout << ans;
}