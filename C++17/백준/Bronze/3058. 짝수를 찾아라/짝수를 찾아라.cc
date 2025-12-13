#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int mn = INT_MAX, sum = 0;
        for(int i = 0; i < 7; i++)
        {
            int tmp;
            cin >> tmp;
            if(tmp % 2 == 0)
            {
                mn = min(mn, tmp);
                sum += tmp;
            }
        }

        cout << sum << ' ' << mn << '\n';
    }
}