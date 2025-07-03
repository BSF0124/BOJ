#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, ans = 0;
vector<int> heavy[102], light[102];
bool vis[102];

bool func(int st, vector<int>(&adj)[])
{
    queue<int> q;
    q.push(st);

    fill(vis, vis+n+1, 0);
    vis[st] = 1;

    int cnt = 0;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur])
        {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
        }
    }
    return cnt >= (n+1)/2;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        heavy[u].push_back(v);
        light[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        ans += (func(i, heavy) || func(i, light));
    
    cout << ans;
}