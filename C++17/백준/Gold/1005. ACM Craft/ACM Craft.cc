#include <bits/stdc++.h>
using namespace std;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        int n, k, w;
        cin >> n >> k;
        vector<int> adj[n+1];
        int dur[n+1], deg[n+1] = {}, dp[n+1];

        for(int i = 1; i <= n; i++)
        {
            cin >> dur[i];
            dp[i] = dur[i];
        }

        while(k--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }

        cin >> w;
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(!deg[i]) q.push(i);

        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur])
            {
                dp[nxt] = max(dp[nxt], dp[cur] + dur[nxt]);
                deg[nxt]--;
                if(!deg[nxt]) q.push(nxt);
            }
        }

        cout << dp[w] << '\n';
    }
}