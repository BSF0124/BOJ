#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second

vector<vector<int>> adj(102);
int dist[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,p1,p2;
    cin >> n >> p1 >> p2 >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    fill(dist, dist+102, -1);
    dist[p1] = 0;
    queue<int> q;
    q.push(p1);

    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur])
        {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    cout << dist[p2];
}