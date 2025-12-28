#include <bits/stdc++.h> 
using namespace std;

int n,m;
unordered_map<string,int> um;
vector<string> ans;

bool cmp(const string& a, const string &b)
{
    if(um[a] != um[b]) return um[a] > um[b];
    if(a.length() != b.length()) return a.length() > b.length();
    return a < b;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    string str;
    while(n--)
    {
        cin >> str;
        if(str.length() >= m)
        {
            um[str]++;
        }
    }

    for(auto &p : um)
        ans.push_back(p.first);

    sort(ans.begin(), ans.end(), cmp);

    for(auto &str : ans)
        cout << str << '\n';
}