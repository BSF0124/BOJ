#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int h, m;
        cin >> h >> m;

        m -= 45;
        if(m < 0)
        {
            m += 60;
            h--;
        }

        if(h < 0) h += 24;

        cout << "Case #" << i << ": " << h << ' ' << m << '\n';
    }
}