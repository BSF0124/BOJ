#include <bits/stdc++.h> 
using namespace std;

int money[6] = {500,100,50,10,5,1};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    n = 1000 - n;

    for(auto i : money)
    {
        ans += n/i;
        n %= i;
    }

    cout << ans;
}