#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    sort(arr, arr+n);

    int mn = 0, mx = arr[n-1], ans = 0;
    while(mn <= mx)
    {
        int mid = (mn + mx) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += min(arr[i], mid); 
        
        if(sum <= m)
        {
            ans = mid;
            mn = mid + 1;
        }
        else mx = mid - 1;
    }
    cout << ans;
}