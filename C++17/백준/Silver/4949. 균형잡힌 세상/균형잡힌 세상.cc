#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        string str;
        getline(cin, str);

        if(str == ".") 
            return 0;

        stack<char> s;
        bool ans = 1;

        for(auto ch : str)
        {
            if(ch == '[' || ch == '(')
                s.push(ch);
            
            else if(ch == ']')
            {
                if(s.empty() || s.top() != '[')
                    ans = 0;
                else 
                    s.pop();
            }

            else if(ch == ')')
            {
                if(s.empty() || s.top() != '(')
                    ans = 0;
                else 
                    s.pop();
            }

            if(!ans) break;
        }
        if(s.size() > 0) ans = 0;
        cout << (ans ? "yes" : "no") << '\n'; 
    }
}