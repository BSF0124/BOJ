#include <bits/stdc++.h>
using namespace std;

int s, v1, v2;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> v1 >> v2;

    int cnt1 = 0, cnt2 = 0, mn = INT_MAX;
    for(int i = s/v1; i >= 0; i--)
    {
        int tmp = s - i * v1;
        if(tmp % v2 == 0)
        {
            cout << i << ' ' << tmp / v2;
            return 0;
        }
    }

    cout << "Impossible";
}