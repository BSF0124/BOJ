#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> us;
    string name;
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        us.insert(name);
    }

    vector<string> v;
    for(int i = 0; i < m; i++)
    {
        cin >> name;
        if(us.find(name) != us.end()) v.push_back(name);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(const auto& str : v)
        cout << str << '\n';
}