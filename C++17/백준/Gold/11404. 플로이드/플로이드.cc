#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        fill(d[i], d[i]+n+1, INF);
        d[i][i] = 0;
    }

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(d[i][j] == INF) cout << 0;
            else cout << d[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}