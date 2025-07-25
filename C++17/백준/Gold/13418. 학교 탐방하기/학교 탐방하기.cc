#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<tuple<int,int,int>> edge;
int p[1002];

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

void solve(bool is_max_calc)
{
    int sum = 0, cnt = 0;
    fill(p, p+1002, -1);
    for(auto [cost, u, v] : edge)
    {
        if(!is_diff_group(u, v)) continue;
        cnt++;
        sum += cost;
        if(cnt == n) break;
    }

    if(is_max_calc) ans += sum*sum;
    else ans -= sum*sum;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    m++;
    while(m--)
    {
        int a, b;
        bool c;
        cin >> a >> b >> c;
        edge.push_back({!c,a,b});
    }
    sort(edge.begin(), edge.end());
    solve(0);

    sort(edge.rbegin(), edge.rend());
    solve(1);
    
    cout << ans;
}
