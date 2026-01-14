#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    unordered_set<string> s;
    unordered_multiset<string> ms;
    
    string name;
    while(getline(cin, name))
    {
        s.insert(name);
        ms.insert(name);
    }
    vector<string> names(s.begin(), s.end());
    sort(names.begin(), names.end());

    for(auto e : names)
    {
        cout << e << ' ';
        cout << fixed << setprecision(4) << (float)100 * ms.count(e) / ms.size() << '\n';
    }
}