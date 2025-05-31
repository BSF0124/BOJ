#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[200002];
int cnt[100002] = {};

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int en = 0, mx = 0;
    cnt[arr[0]]++;
    for(int st = 0; st < n; st++)
    {
        while(en < n-1 && cnt[arr[en+1]] < k)
        {
            cnt[arr[++en]]++;
        }
        mx = max(mx, en-st+1);
        cnt[arr[st]]--;
    }

    cout << mx;
}