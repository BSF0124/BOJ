#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, e, v1, v2;
vector<pair<int,int>> adj[802];

long long func(int st, int en)
{
    int d[802];
    fill(d, d+n+1, INF);
    d[st] = 0;

    priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

    pq.push({0,st});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    return d[en];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    int a, b, c;
    while(e--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    cin >> v1 >> v2;
    long long ans1 = func(1,v1)+func(v1,v2)+func(v2,n);
    long long ans2 = func(1,v2)+func(v2,v1)+func(v1,n);
    long long ans = min(ans1, ans2);
    if(ans >= INF) ans = -1;
    cout << ans;
}