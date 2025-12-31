#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long s, sum = 0, ans = 0;
    cin >> s;
    {
        for(long long i = 1; i <= s; i++)
        {
            sum += i;
            ans++;

            if(sum > s)
            {
                ans--;
                break;
            }

            if(sum == s)
                break;
        }
    }

    cout << ans;
}