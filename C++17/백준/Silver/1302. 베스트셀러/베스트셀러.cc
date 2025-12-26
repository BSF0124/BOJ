#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> cnt;
    string str;
    while(n--)
    {
        cin >> str;
        cnt[str]++;
    }

    int mx = 0;
    string ans;

    for(const auto& p : cnt)
    {
        if(p.second > mx)
        {
            mx = p.second;
            ans = p.first;
        }
    }

    cout << ans;
}