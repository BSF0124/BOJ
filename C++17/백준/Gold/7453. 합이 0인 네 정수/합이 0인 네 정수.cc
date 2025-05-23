#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[4][4002];
vector<long long> v1, v2; 

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[j][i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            v1.push_back(arr[0][i] + arr[1][j]);
            v2.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(v2.begin(), v2.end());

    long long ans = 0;
    for(auto i : v1)
    {
        auto lb = lower_bound(v2.begin(), v2.end(), -i);
        auto ub = upper_bound(v2.begin(), v2.end(), -i);
        ans += ub - lb;
    }

    cout << ans;
}