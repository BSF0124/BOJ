#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    string str;
    while(n--)
    {
        cin >> str;
        stack<char> s;
        for(auto c : str)
        {
            if(s.empty() || s.top() != c) s.push(c);
            else s.pop();
        }
        ans += s.size() == 0;
    }
    cout << ans;
}