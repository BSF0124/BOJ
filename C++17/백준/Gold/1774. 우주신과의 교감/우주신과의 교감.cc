#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<tuple<long long,int,int>> edge;
pair<int, int> space[1002];
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

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        space[i] = {x,y};
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            int dx = space[j].first - space[i].first;
            int dy = space[j].second - space[i].second;
            long long dist = (long long)dx*dx + (long long)dy*dy;
            edge.push_back({dist, i, j});
        }
    }
    sort(edge.begin(), edge.end());

    int cnt = 0;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        if(is_diff_group(u, v)) cnt++;
    }

    double ans = 0;
    for(auto e : edge)
    {
        auto[dist, a, b] = e;
        if(!is_diff_group(a, b)) continue;
        ans += sqrt(dist);
        cnt++;
        if(cnt == n-1) break;
    }

    cout << fixed << setprecision(2) << ans;
}
