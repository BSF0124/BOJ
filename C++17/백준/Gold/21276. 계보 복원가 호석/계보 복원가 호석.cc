#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

string name[1002];
unordered_map<string, int> um;

vector<int> tree[1002];
vector<int> child[1002];
int deg[1002];


int main(void)
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> name[i];

    sort(name+1, name+1+n);

    for(int i = 1; i <= n; i++)
        um[name[i]] = i;
    
    cin >> m;
    while(m--)
    {
        cin >> s1 >> s2;
        tree[um[s2]].push_back(um[s1]);
        deg[um[s1]]++;
    }

    vector<int> v;
    for(int i = 1; i <= n; i++)
        if(!deg[i]) v.push_back(i);
    
    cout << v.size() << '\n';
    for(auto i : v) cout << name[i] << ' ';
    cout << '\n';

    for(int i = 1; i <= n; i++)
    {
        sort(tree[i].begin(), tree[i].end());
        for(auto c : tree[i])
            if(deg[c] - deg[i] == 1) child[i].push_back(c);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << name[i] << ' ' << child[i].size() << ' ';
        for(auto c : child[i]) cout << name[c] << ' ';
        cout << '\n';
    }
}