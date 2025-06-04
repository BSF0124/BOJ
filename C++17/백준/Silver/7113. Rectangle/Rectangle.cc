#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(1)
    {
        if(n == m)
        {
            ans++;
            break;
        }

        else if(n == 1 || m == 1)
        {
            ans += max(n , m);
            break;
        }

        else
        {
            ans++;
            if(n < m) m -= n;
            else n -= m;
        }
    }
    cout << ans; 
}