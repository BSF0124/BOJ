#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;

        int ans = 0;
        while(n != 6174)
        {
            vector<int> v;
            for(int i = 0; i < 4; i++)
            {
                v.push_back(n % 10);
                n /= 10;
            }
            sort(v.begin(), v.end());

            int mn = 0 ,mx = 0;
            for(int i = 0; i < 4; i++)
            {
                mn += pow(10, i) * v[3-i];
                mx += pow(10, i) * v[i];
            }

            n = mx - mn;
            ans++;
        }
        cout << ans << '\n';
    }
}