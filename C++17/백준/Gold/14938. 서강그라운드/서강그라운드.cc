#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, r;
int d[102][102];
int item[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++)
        cin >> item[i];

    for(int i = 1; i <= n; i++)
    {
        fill(d[i], d[i]+1+n, INF);
        d[i][i] = 0;
    }

    while(r--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(d[i][j] <= m) cnt += item[j];
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}