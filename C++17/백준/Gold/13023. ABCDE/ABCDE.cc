#include <bits/stdc++.h> 
using namespace std;

vector<int> adj[2002];
bool vis[2002];
int n,m;
bool ans = 0;

void dfs(int cur, int cnt)
{
    if(ans) return;
    if(cnt == 4)
    {
        ans = 1;
        return;
    }

    vis[cur] = 1;

    for(auto nxt : adj[cur])
        if(!vis[nxt])
            dfs(nxt, cnt+1);

    vis[cur] = 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++)
    {
        dfs(i, 0);
        if(ans) break;
    }

    cout << ans;
}