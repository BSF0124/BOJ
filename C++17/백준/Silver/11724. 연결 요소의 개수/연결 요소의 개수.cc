#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
vector<int> adj[1002];
bool vis[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;

        stack<int> s;
        s.push(i);
        vis[i] = 1;
        ans++;

        while(!s.empty())
        {
            int cur = s.top(); s.pop();
            for(auto nxt : adj[cur])
            {
                if(vis[nxt]) continue;
                s.push(nxt);
                vis[nxt] = 1;
            }
        }
    }
    cout << ans;
}
