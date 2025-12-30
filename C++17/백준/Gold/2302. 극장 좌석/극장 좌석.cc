#include <bits/stdc++.h> 
using namespace std;

int n,m;
int d[42];
vector<int> v1, v2;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    v1.push_back(0);
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    v1.push_back(n+1);

    for(int i = 1; i < v1.size(); i++)
    {
        int tmp = v1[i] - v1[i-1] - 1;
        if(tmp != 0) v2.push_back(tmp);
    }

    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = d[i-1] + d[i-2];

    int ans = 1;
    for(auto i : v2)
        ans *= d[i];

    cout << ans;
}