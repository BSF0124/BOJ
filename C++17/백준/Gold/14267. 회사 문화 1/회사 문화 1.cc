#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100002];
int p[100002];
int cnt[100002] = {};

void dfs(int cur)
{
    if(p[cur] != -1)
        cnt[cur] += cnt[p[cur]];
        
    for(auto nxt : adj[cur])
        dfs(nxt);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];

        if(p[i] != -1)
            adj[p[i]].push_back(i);
    }

    while(m--)
    {
        int i, w;
        cin >> i >> w;
        cnt[i] += w;
    }

    dfs(1);

    for(int i = 1; i <= n; i++)
        cout << cnt[i] << ' ';
}