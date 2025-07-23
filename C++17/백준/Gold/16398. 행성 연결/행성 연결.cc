#include <bits/stdc++.h>
using namespace std;

int n, e = 0;
tuple<int,int,int> edge[1000002];
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

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int cost;
            cin >> cost;
            if(i >= j) continue;
            edge[e++] = {cost, i, j};
        }
    }
    sort(edge, edge+e);

    int cnt = 0;
    long long ans = 0;
    for(int i = 0; i < e; i++)
    {
        auto[cost, a, b] = edge[i];
        if(!is_diff_group(a,b)) continue;
        cnt++;
        ans += cost;
        if(cnt == n-1) break;
    }

    cout << ans;
}
