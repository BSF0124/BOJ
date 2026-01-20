#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    unordered_set<string> s;
    string a, b;
    while(n--)
    {
        cin >> a >> b;

        if((a == "ChongChong" || b == "ChongChong") && s.empty())
        {
            s.insert(a);
            s.insert(b);
            ans = 2;
        }

        else if(s.find(a) != s.end() && s.find(b) != s.end())
            continue;

        else if(s.find(a) != s.end())
        {
            s.insert(b);
            ans++;
        }

        else if(s.find(b) != s.end())
        {
            s.insert(a);
            ans++;
        }
    }

    cout << ans;
}