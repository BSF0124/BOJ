#include <bits/stdc++.h> 
using namespace std;

int n;
long long ans = 0;
long long dist[100002], price[100002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n-1; i++)
        cin >> dist[i];
    for(int i = 0; i < n; i++)
        cin >> price[i];

    long long cur = price[0];
    for(int i = 0; i < n-1; i++)
    {
        if(price[i] < cur)
            cur = price[i];

        ans += cur * dist[i];
    }

    cout << ans;
}