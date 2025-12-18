#include <bits/stdc++.h> 
using namespace std;

int n, ans = 0;
int arr[8];

int func()
{
    int sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        int tmp = arr[i] - arr[i+1];
        sum += abs(tmp);
    }

    return sum;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    do
    {
        ans = max(ans, func());
    } while (next_permutation(arr, arr+n));

    cout << ans;
}