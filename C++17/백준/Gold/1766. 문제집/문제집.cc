#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32002];
int deg[32002];

vector<int> ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++)
        if(!deg[i]) pq.push(i);

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        cout << cur << ' ';
        
        for(auto nxt : adj[cur])
        {
            deg[nxt]--;
            if(!deg[nxt]) pq.push(nxt);
        }
    }
}