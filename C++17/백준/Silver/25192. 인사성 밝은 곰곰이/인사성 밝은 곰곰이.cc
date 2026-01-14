#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<string> s;
    int n, ans = 0;
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        if(str == "ENTER")
            s.clear();

        else if(s.find(str) == s.end())
        {
            ans++;
            s.insert(str);
        }
    }
    cout << ans;
}