#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int st = 0, en = 0;
    int mn = INT_MAX;
    while(en < n)
    {
        int diff = arr[en] - arr[st];

        if(diff < m) en++;
        else
        {
            mn = min(mn, diff);
            st++;
        }
    }
    cout << mn;
}