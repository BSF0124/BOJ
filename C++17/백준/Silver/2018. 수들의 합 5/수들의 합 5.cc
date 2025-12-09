#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int n;
    cin >> n;
        
    int st = 1, en = 2, sum = 3, ans = 0;
    while(st < en)
    {
        if(sum == n)
            ans++;
            
        if(sum >= n)
            sum -= st++;

        else
            sum += ++en;
    }
        
    cout << ans+1;
}