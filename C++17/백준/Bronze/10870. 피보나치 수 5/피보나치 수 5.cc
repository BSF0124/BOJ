#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
ll fibo[22];

ll func(int n)
{
    if(n <= 1) return n;

    if(fibo[n] != -1) return fibo[n];

    fibo[n] = func(n-1) + func(n-2);
    return fibo[n];
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    fill(fibo, fibo+22, -1);
    cout << func(n);
}