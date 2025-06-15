#include <bits/stdc++.h>
using namespace std;

int n, d;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n <= 3)
    {
        for(int i = 1; i <= n; i++)
            cout << i << ' ';
        return 0;
    }

    d = n/2;

    if(n%2) cout << 1 << ' ';
    
    for(int i = 0; i < d; i++)
    {
        cout << n-d-i << ' ' << n-i << ' ';
    }
}