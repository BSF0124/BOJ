#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, en = 0;
    int mn = INT_MAX, sum = arr[0];
    while(en < n)
    {
        if(sum >= s)
        {
            mn = min(mn, en - st + 1);
            sum -= arr[st++];
        }
        else if(++en < n)
        {
            sum += arr[en];
        }

    }

    if(mn == INT_MAX) mn = 0;
    cout << mn;
}