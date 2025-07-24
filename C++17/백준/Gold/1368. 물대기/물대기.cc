#include <bits/stdc++.h>
using namespace std;

int n, cost;
vector<pair<int,int>> adj[100002];
bool chk[100002];
priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> cost;
        adj[0].push_back({cost, i});
        adj[i].push_back({cost, 0});
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost;
            if(i >= j) continue;
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }
    }
    chk[0] = 1;
    for(auto nxt : adj[0]) pq.push(nxt);

    int cnt = 0, ans = 0;
    while(cnt < n)
    {
        auto cur =  pq.top(); pq.pop();
        if(chk[cur.second]) continue;
        chk[cur.second] = 1;
        cnt++;
        ans += cur.first;
        for(auto nxt : adj[cur.second])
            if(!chk[nxt.second]) pq.push(nxt);
    }

    cout << ans;
}
