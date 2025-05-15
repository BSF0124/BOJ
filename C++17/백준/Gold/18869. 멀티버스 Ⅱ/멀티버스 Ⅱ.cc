#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[102][10002];

bool compare(int a[], int b[])
{
    for(int i = 0; i < m; i++)
        if(a[i] != b[i]) return 0;

    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    for(int i = 0; i < m; i++)
    {
        vector<int> v(arr[i], arr[i]+n);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        for(int j = 0; j < n; j++)
            arr[i][j] = lower_bound(v.begin(), v.end(), arr[i][j]) - v.begin();
    }

    int ans = 0;
    for(int i = 0; i < m-1; i++)
        for(int j = i+1; j < m; j++)
            ans += compare(arr[i], arr[j]);
            
    cout << ans;
}