#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, q;
int d[302][302][302];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> d[0][i][j];
            if(i != j && d[0][i][j] == 0) d[0][i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++)
        for(int s = 1; s <= n; s++)
            for(int e = 1; e <= n; e++)
                d[i][s][e] = min(d[i-1][s][e], d[i-1][s][i] + d[i-1][i][e]);

    while(q--)
    {
        int c, s, e;
        cin >> c >> s >> e;

        int ans = d[c-1][s][e];
        if(ans > 170324) cout << -1;
        else cout << ans;
        cout << '\n';
    }
}