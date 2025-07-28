#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int,int,int>> edge;
vector<pair<int,int>> x;
vector<pair<int,int>> y;
vector<pair<int,int>> z;
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

    cin >> n;

    int xx, yy, zz;
    for(int i = 0; i < n; i++)
    {
        cin >> xx >> yy >> zz;
        x.push_back({xx, i});
        y.push_back({yy, i});
        z.push_back({zz, i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for(int i = 1; i < n; i++)
    {
        edge.push_back({abs(x[i-1].first - x[i].first), x[i-1].second, x[i].second});
        edge.push_back({abs(y[i-1].first - y[i].first), y[i-1].second, y[i].second});
        edge.push_back({abs(z[i-1].first - z[i].first), z[i-1].second, z[i].second});
    }
    sort(edge.begin(), edge.end());

    int cnt = 0, ans = 0;
    for(auto [cost, u, v] : edge)
    {
        if(!is_diff_group(u,v)) continue;
        ans += cost;
        cnt++;
        if(cnt == n-1) break;
    }
    cout << ans;
}
