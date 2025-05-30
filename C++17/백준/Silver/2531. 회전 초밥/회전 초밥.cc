#include <bits/stdc++.h>
using namespace std;

int n, d, k ,c;
int arr[30002];
int cnt[3002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int kind = 0;
    for(int i = 0; i < k; i++)
        if(cnt[arr[i]]++ == 0) kind++;
    
    int ans = kind + (cnt[c] == 0);

    for(int st = 1; st < n; st++)
    {
        if(--cnt[arr[st-1]] == 0) kind--;

        int en = (st + k - 1) % n;
        if(cnt[arr[en]]++ == 0) kind++;

        ans = max(ans, kind + (cnt[c] == 0));
    }

    cout << ans;
}