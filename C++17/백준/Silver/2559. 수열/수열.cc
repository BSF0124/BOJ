#include <bits/stdc++.h> 
using namespace std;

int n, k;
int arr[100002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int st = 0, en = 0, ans = INT_MIN, sum = arr[0];
    while(en < n)
    {
        if(en-st+1 == k)
        {
            ans = max(ans, sum);
            sum -= arr[st++];
        }
        else if(++en < n)
        {
            sum += arr[en];
        }
    }

    cout << ans;
}