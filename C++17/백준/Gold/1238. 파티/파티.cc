#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m, x;

vector<pair<int,int>> adj[1002];

int func(int st, int en)
{
    int d[1002];
    fill(d, d+n+1, INF);
    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    d[st] = 0;
    pq.push({0, st});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return d[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;
    
    while(m--)
    {
        int st, en, t;
        cin >> st >> en >> t;
        adj[st].push_back({t,en});
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, func(i,x) + func(x,i));
    }
    cout << ans;
}