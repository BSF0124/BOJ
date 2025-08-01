#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, k;
int d[202][202];
int f[202];

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
        int a, b, t;
        cin >> a >> b >> t;
        d[a][b] = min(d[a][b], t);
    }

    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> f[i];
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++)
    {
        int mx = 0;
        for(int j = 1; j <= k; j++)
            mx = max(mx, d[i][f[j]] + d[f[j]][i]);
        v.push_back({mx, i});
    }
    sort(v.begin(), v.end());

    int mn = v[0].first;
    for(auto cur : v)
    {
        if(mn < cur.first) break;
        cout << cur.second << ' ';
    }
}