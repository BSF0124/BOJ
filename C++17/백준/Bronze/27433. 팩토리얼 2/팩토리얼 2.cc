#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

ll func(int n)
{
    if(n == 0) return 1;
    return n * func(n-1);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << func(n);
}