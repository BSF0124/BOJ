#include <bits/stdc++.h>
using namespace std;

int n, m, k;
tuple<int,int,int> edge[100002];
vector<int> p(1002, -1);

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

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        is_diff_group(0, tmp);
    }

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {w,u,v};
    }
    sort(edge, edge+m);


    int cnt = 0, ans = 0;
    for(int i = 0; i < m; i++)
    {
        auto [w, u ,v] = edge[i];
        if(!is_diff_group(u,v)) continue;
        cnt++;
        ans += w;
        if(cnt == n) break;
    }
    cout << ans;
}
