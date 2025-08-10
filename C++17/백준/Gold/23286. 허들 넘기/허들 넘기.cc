#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 
int n, m, t;
int d[302][302];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    for(int i = 1; i <= n; i++)
    {
        fill(d[i]+1, d[i]+1+n, INF);
        d[i][i] = 0;
    }

    while(m--)
    {
        int u, v, h;
        cin >> u >> v >> h;
        d[u][v] = h;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));

    while(t--)
    {
        int s, e;
        cin >> s >> e;
        if(d[s][e] == INF) cout << "-1\n";
        else cout << d[s][e] << '\n';
    }
}