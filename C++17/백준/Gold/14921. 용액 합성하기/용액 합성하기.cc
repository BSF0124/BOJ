#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, en = n-1;
    int ans = INT_MAX;
    while(st < en)
    {
        int sum = arr[st] + arr[en];

        if(abs(sum) < abs(ans))
            ans = sum;

        if(sum < 0) st++;
        else en--;
    }

    cout << ans;
}