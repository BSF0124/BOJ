#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1002];
int deg[1002];
queue<int> q;
vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int tmp, u, v;
        cin >> tmp >> u;
        for(int i = 0; i < tmp-1; i++)
        {
            cin >> v;
            adj[u].push_back(v);
            deg[v]++;
            u = v;
        }
    }

    for(int i = 1; i <= n; i++)
        if(!deg[i]) q.push(i);

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        ans.push_back(cur);

        for(auto nxt : adj[cur])
        {
            deg[nxt]--;
            if(!deg[nxt]) q.push(nxt);
        }
    }

    if(ans.size() != n) cout << 0;
    else for(auto i : ans) cout << i << ' ';
}