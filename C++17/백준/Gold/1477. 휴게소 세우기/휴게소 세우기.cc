#include <bits/stdc++.h> 
using namespace std;

int n, m, l;
int v[52];

bool func(int x)
{
    int cnt = 0, pre = 0;
    for(int i = 0; i <= n; i++)
    {
        int dist = v[i] - pre;
        if(dist >= x) cnt += (dist-1) / x;
        pre = v[i];
    }

    return cnt > m;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v+n);
    v[n] = l;

    int st = 1, en = l;
    while(st < en)
    {
        int mid = (st+en) / 2;
        if(func(mid)) st = mid+1;
        else en = mid;
    }

    cout << st;
}