#include <bits/stdc++.h>
using namespace std;

int k, n, m, u, v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    while(k--)
    {
        cin >> n >> m;
        
        vector<int> adj[n+1];
        int chk[n+1];
        fill(chk, chk+n+1, -1);
        bool ans = 1;

        while(m--)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 1; i <= n; i++)
        {
            if(chk[i] != -1) continue;
            
            queue<int> q;
            q.push(i);
            chk[i] = 0;

            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                for(auto nxt : adj[cur])
                {
                    if(chk[nxt] != -1)
                    {
                        if(chk[nxt] == chk[cur]) ans = 0;
                        continue;
                    }
                    q.push(nxt);
                    chk[nxt] = (chk[cur] + 1) % 2;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}