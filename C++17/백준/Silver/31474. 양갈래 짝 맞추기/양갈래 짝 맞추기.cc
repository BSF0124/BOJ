#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, ans = 1;
    cin >> n;

    for(int i = 2; i <= n; i+=2)
        ans *= i-1;
    
    cout << ans;
}
