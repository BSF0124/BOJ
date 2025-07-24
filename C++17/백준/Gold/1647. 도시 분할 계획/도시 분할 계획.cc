#include <bits/stdc++.h>
using namespace std;

int n, m;
tuple<int,int,int> edge[1000002];
vector<int> p(100002, -1);

int find(int x)
{
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
{
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge, edge+m);

    if(n == 2)
    {
        cout << 0;
        return 0;
    }

    int cnt = 0, ans = 0;
    for(int i = 0; i < m; i++)
    {
        int cost, a, b;
        tie(cost,a,b) = edge[i];
        if(!is_diff_group(a,b)) continue;
        ans += cost;
        cnt++;
        if(cnt == n-2) break;
    }

    cout << ans;
}
