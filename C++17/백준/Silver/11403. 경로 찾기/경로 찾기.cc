#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> adj[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp) adj[i].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            bool chk = 0;
            queue<int> q;
            q.push(i);
            bool vis[102] = {};
            vis[i] = 1;

            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                
                for(auto nxt : adj[cur])
                {
                    if(nxt == j) chk = 1;

                    if(vis[nxt]) continue;
                    q.push(nxt);
                    vis[nxt] = 1;
                }
            }
            cout << chk << ' ';
        }
        cout << '\n';
    }
}