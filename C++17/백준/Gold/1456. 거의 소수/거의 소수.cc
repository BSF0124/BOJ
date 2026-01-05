#include <bits/stdc++.h> 
using namespace std;

long long a, b;
int ans = 0; 

vector<int> sieve(int n)
{
    vector<int> primes;
    vector<bool> state(n+1, 1);
    state[1] = 0;

    for(int i = 2; i*i <= n; i++)
    {
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
            state[j] = 0;
    }

    for(int i = 2; i <= n; i++)
        if(state[i]) primes.push_back(i);
    return primes;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    vector<int> primes = sieve(10000000);
    for(auto p : primes)
        for(long long i = p; i <= b / p; i *= p)
            ans += (i * p >= a);
    cout << ans;
}