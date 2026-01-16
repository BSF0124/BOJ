#include <bits/stdc++.h> 
using namespace std;

int n, d, k, c;
int cur = 0, ans = 0;
int dish[3000002];
int cnt[3002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;

    for(int i = 0; i < n; i++)
        cin>> dish[i];

    for(int i = 0; i < k; i++)
    {
        if(!cnt[dish[i]]) cur++;
        cnt[dish[i]]++;
    }

    ans = cur + (!cnt[c]);

    for(int i = 1; i < n; i++)
    {
        int eli = dish[i-1];
        int add = dish[(i+k-1) % n];

        cnt[eli]--;
        if(!cnt[eli]) cur--;

        if(!cnt[add]) cur++;
        cnt[add]++;

        ans = max(ans, cur + (!cnt[c]));
    }

    cout << ans;
}