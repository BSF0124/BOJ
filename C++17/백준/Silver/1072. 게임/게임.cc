#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x, y, z;
    cin >> x >> y;
    z = 100 * y / x;

    if(z >= 99)
    {
        cout << -1;
        return 0;
    }

    long long st = 1, en = x, ans = -1;
    while(st <= en)
    {
        long long mid = (st+en) / 2;
        long long _z = (100 * (y+mid)) / (x+mid);
        if(_z> z)
        {
            ans = mid;
            en = mid-1;
        }
        else st = mid+1;
    }

    cout << ans;
}