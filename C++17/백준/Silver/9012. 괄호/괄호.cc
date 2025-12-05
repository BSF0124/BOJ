#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    while(n--)
    {
        cin >> str;
        stack<int> s;
        bool ans = 1;
        for(auto c : str)
        {
            if(c == '(') s.push(1);
            else
            {
                if(s.empty())
                {
                    ans = 0;
                    break;
                }
                else s.pop();
            }
        }
        if(ans && !s.empty()) ans = 0;
        cout << (ans? "YES" : "NO") << '\n';
    }
}