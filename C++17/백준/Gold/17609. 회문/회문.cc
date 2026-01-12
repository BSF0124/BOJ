#include <bits/stdc++.h> 
using namespace std;

bool check(const string& str, int st, int en)
{
    while(st < en)
    {
        if(str[st] != str[en])
            return 0;
        st++;
        en--;
    }
    return 1;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    string str;
    while(t--)
    {
        cin >> str;
        bool ans = 1, removed = 0;
        int st = 0, en = str.size()-1;
        while(st < en)
        {
            if(str[st] == str[en])
            {
                st++;
                en--;
            }

            else
            {
                if(check(str, st+1, en) || check(str, st, en-1))
                    removed = 1;
                else
                    ans = 0;
                break;
            }
        }

        if(!ans) cout << 2 << '\n';
        else if(removed) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}