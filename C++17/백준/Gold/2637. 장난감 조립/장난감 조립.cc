#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> adj[102];
int deg[102] = {};
int cnt[102] = {};
bool res[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(res+1, res+n, 1);

    while(m--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        adj[x].push_back({y,k});
        deg[y]++;
        res[x] = 0;
    }
    
    cnt[n] = 1;
    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(auto [nxt,c]: adj[cur])
        {
            cnt[nxt] += cnt[cur] * c;
            deg[nxt]--;
            if(!deg[nxt]) q.push(nxt);
        }
    }

    for(int i = 1; i <= n-1; i++)
        if(res[i]) 
            cout << i << ' ' << cnt[i] << '\n';
}
