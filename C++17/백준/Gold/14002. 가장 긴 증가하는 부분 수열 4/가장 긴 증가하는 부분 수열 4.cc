#include <bits/stdc++.h> 
using namespace std;

int n;
int arr[1002], d[1002], pre[1002];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        d[i] = 1;
        pre[i] = -1;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(arr[j] < arr[i] && d[j]+1 > d[i]) 
            {
                d[i] = d[j]+1;
                pre[i] = j;
            }
        }
    }

    int len = 0, idx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] > len)
        {
            len = d[i];
            idx = i;
        }
    }

    vector<int> v;
    while(idx != -1)
    {
        v.push_back(arr[idx]);
        idx = pre[idx];
    }
    reverse(v.begin(), v.end());

    cout << len << '\n';
    for(int i : v) cout << i << ' ';
}