#include <bits/stdc++.h>
using namespace std;

int n, en = 1, ans = 0;
int l[100002] = {}, r[100002] = {}, p[100002] = {};
vector<bool> vis(100002);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[1] = -1;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        l[a] = b;
        r[a] = c;
        p[b] = a;
        p[c] = a;
    }

    int en = 1;
    while(r[en] != -1) en = r[en];

    int cur = 1;
    while(1)
    {
        vis[cur] = 1;
        ans++;
        
        if(l[cur] != -1 && !vis[l[cur]])
            cur = l[cur];
        
        else if(r[cur] != -1 && !vis[r[cur]])
            cur = r[cur];
        
        else
        {
            if(cur == en) break;
            else cur = p[cur];
        }
    }
    cout << ans-1;
}