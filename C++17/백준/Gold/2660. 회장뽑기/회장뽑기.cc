#include <bits/stdc++.h>
using namespace std;

int n, mn = INT_MAX, cnt = 0;
vector<int> adj[52];
int score[52];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(1)
    {
        int u, v;
        cin >> u >> v;

        if(u == -1 && v == -1) break;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        queue<int> q;
        int dist[n+1];

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

        score[i] = *max_element(dist, dist+n+1);
        mn = min(mn, score[i]);
    }

    for(int i = 1; i <= n; i++)
        cnt += (mn == score[i]);

    cout << mn << ' ' << cnt << '\n';
    for(int i = 1; i <= n; i++)
        if(mn == score[i]) cout << i << ' ';
}