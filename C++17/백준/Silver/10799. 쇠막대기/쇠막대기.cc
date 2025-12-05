#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    int result = 0;
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(')
            S.push('(');
    
        else
        {
            S.pop();
            if(str[i - 1] == '(')
            {
                result += S.size();
            }
            else
            {
                result++;
            }
        }
    }
    
    cout << result;
}