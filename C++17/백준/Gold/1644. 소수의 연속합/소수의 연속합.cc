#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> primes;
    vector<bool> chk(n+1, 1);
    chk[0] = 0;
    chk[1] = 0;

    for(int i = 2; i*i <= n; i++)
    {
        if(!chk[i]) continue;
        for(int j = i*i; j <= n; j+= i)
            chk[j] = 0;
    }

    for(int i = 2; i <= n; i++)
        if(chk[i]) primes.push_back(i);

    int en = 0, sum = primes[0], ans = 0;
    for(int st = 0; st < primes.size(); st++)
    {
        while(en < primes.size() && sum < n)
        {
            en++;
            if(en != primes.size())
            {
                sum += primes[en];
            }
        }
        if(en == primes.size()) break;
        if(sum == n) ans++;
        sum -= primes[st];
    }

    cout << ans;
}