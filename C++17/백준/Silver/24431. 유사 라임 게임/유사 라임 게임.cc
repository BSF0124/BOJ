#include <bits/stdc++.h>
using namespace std;

int t,n,l,f;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        int ans = 0;
        unordered_map<string,int> m;

        cin >> n >> l >> f;
        while(n--) 
        {
            string str;
            cin >> str;

            string tmp = str.substr(str.size() - f);
            m[tmp]++;
        }
        
        for(auto &e : m) ans += e.second / 2;
        cout << ans << '\n';
    }
}