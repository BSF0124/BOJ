#include <bits/stdc++.h>
using namespace std;

int n;
string str, tmp;
unordered_map<char, int> m;

bool cmp(const string& a, const string& b)
{
    int len = min(a.size(), b.size());

    for(int i = 0; i < len; i++)
        if(m[a[i]] != m[b[i]])
            return m[a[i]] < m[b[i]];
    
    return a.size() < b.size();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    while(1)
    {
        cnt++;
        cin >> n;
        if(n == 0) return 0;

        cin >> tmp;
        m.clear();
        for(int i = 0; i < tmp.size(); i++)
            m[tmp[i]] = i;
        
        vector<string> v;
        while(n--)
        {
            cin >> tmp;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), cmp);
        cout << "year " << cnt << '\n';
        for(auto s : v)
            cout << s << '\n';
    }
}