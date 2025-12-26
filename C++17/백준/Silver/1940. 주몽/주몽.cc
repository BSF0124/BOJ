#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt[100002] = {};
    int n, m, ans = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    for(int i = 1; i <= m/2; i++)
    {
        int j = m-i;

        if(j > 100000) continue;

        if(i == j) ans += cnt[i]/2;
        else ans += min(cnt[i], cnt[j]);
    }

    cout << ans;
}