#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> s;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        string name, commute;
        cin >> name >> commute;

        if(commute == "enter") s.insert(name);
        else s.erase(name);
    }

    vector<string> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end(), greater<string>());
    for(auto s : ans) cout << s << '\n';
}