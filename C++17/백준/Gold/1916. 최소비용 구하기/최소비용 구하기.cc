#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m;
vector<pair<int,int>> adj[1002];
int d[1002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }
    
    int st, en;
    cin >> st >> en;
    
    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    
    fill(d, d+n+1, INF);
    d[st] = 0;
    pq.push({0, st});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= nxt.X + d[cur.Y]) continue;
            d[nxt.Y] = nxt.X + d[cur.Y];
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    cout << d[en];
}