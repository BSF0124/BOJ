#include <bits/stdc++.h>
using namespace std;

int k, l;
unordered_map<string, int> m;

bool cmp(pair<string,int>& a, pair<string,int>& b)
{
    return a.second < b.second;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> l;
    for(int i = 0; i < l; i++)
    {
        string id;
        cin >> id;
        m[id] = i;
    }

    vector<pair<string,int>> ans(m.begin(), m.end());
    sort(ans.begin(), ans.end(), cmp);

    for(int i = 0; i < min(k, (int)ans.size()); i++)
        cout << ans[i].first << '\n';
}