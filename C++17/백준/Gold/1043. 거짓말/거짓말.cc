#include <bits/stdc++.h>
using namespace std;

int n, m, t, ans = 0;
vector<int> adj[52];
vector<int> party[52]; 
bool chk[52] = {};

bool func(int num)
{
    for(auto i : party[num])
        if(chk[i]) return 0;
    
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    while(t--)
    {
        int tmp;
        cin >> tmp;
        chk[tmp] = 1;
    }

    for(int i = 1; i <= m; i++)
    {
        int tmp, p1, p2;
        cin >> tmp >> p1;
        party[i].push_back(p1);
        while(--tmp)
        {
            cin >> p2;
            party[i].push_back(p2);
            adj[p1].push_back(p2);
            adj[p2].push_back(p1);
            swap(p1,p2);
        }

    }

    for(int i = 1; i <= n; i++)
    {
        queue<int> q;
        if(chk[i]) q.push(i);
        while(!q.empty())
        {
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur])
            {
                if(chk[nxt]) continue;
                chk[nxt] = 1;
                q.push(nxt);
            }
        }
    }

    for(int i = 1; i <= m; i++)
        ans += func(i);
    cout << ans;
}