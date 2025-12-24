#include <bits/stdc++.h> 
using namespace std;

int t, n;
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        vector<pair<int,int>> v;

        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }

        sort(v.begin(), v.end());

        int ans = 1, tmp = v[0].second;

        for(int i = 1; i < n; i++)
        {
            if(v[i].second < tmp)
            {
                ans++;
                tmp = v[i].second;
            }
        }

        cout << ans << '\n';
    }
}