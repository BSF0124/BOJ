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
        long long x, y;
        cin >> x >> y;

        long long d = y - x;
        long long n = (long long)floor(sqrt(d));

        if(d == n * n)
            cout << 2 * n - 1 << '\n';
        else if(d <= n * n + n)
            cout << 2 * n << '\n';
        else
            cout << 2 * n + 1 << '\n';
    }
}