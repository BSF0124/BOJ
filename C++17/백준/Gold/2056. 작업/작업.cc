#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[10002];
int dp[10002];
int deg[10002];
int hour[10002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> hour[i];
        dp[i] = hour[i];

        int m;
        cin >> m;
        while(m--)
        {
            int v;
            cin >> v;
            adj[v].push_back(i);
            deg[i]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(!deg[i]) q.push(i);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur])
        {
            dp[nxt] = max(dp[nxt], dp[cur] + hour[nxt]);
            deg[nxt]--;
            if(!deg[nxt]) q.push(nxt);
        }
    }

    cout << *max_element(dp+1, dp+1+n);
}