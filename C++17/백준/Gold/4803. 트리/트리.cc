#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 0;
    while(1)
    {
        tmp++;
        cin >> n >> m;
        if(n == 0 &&  m == 0) return 0;

        vector<int> adj[n+1];
        int p[n+1] = {};
        while(m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(p[i] != 0) continue;
            bool chk = 1;

            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                for(auto nxt : adj[cur])
                {
                    if(p[cur] == nxt) continue;
                    if(p[nxt] != 0)
                    {
                        chk = 0;
                        continue;
                    }
                    q.push(nxt);
                    p[nxt] = cur;
                }
            }

            cnt += chk;
        }

        cout << "Case " << tmp << ": ";
        if(cnt == 0) cout << "No trees.\n";
        else if(cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
    }
}