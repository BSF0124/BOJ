#include <bits/stdc++.h> 
using namespace std;

int n,c;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int st = 1, en = v[n-1] - v[0], ans = 0;
    while(st <= en)
    {
        int mid = (st+en) / 2;
        int cnt = 1, tmp = v[0];

        for(int i = 1; i < n; i++)
        {
            if(v[i] - tmp >= mid)
            {
                cnt++;
                tmp = v[i];
            }
        }

        if(cnt >= c)
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }

    cout << ans;
}