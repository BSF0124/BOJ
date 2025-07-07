#include <bits/stdc++.h>
using namespace std;

int m, tmp;
string str;
unordered_set<int> s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    while(m--)
    {
        cin >> str;
        if(str == "add")
        {
            cin >> tmp;
            s.insert(tmp);
        }
        else if(str == "remove")
        {
            cin >> tmp;
            s.erase(tmp);
        }
        else if(str == "check")
        {
            cin >> tmp;
            cout << (s.find(tmp) != s.end()) << '\n';
        }
        else if(str == "toggle")
        {
            cin >> tmp;
            if(s.find(tmp) != s.end()) s.erase(tmp);
            else s.insert(tmp);
        }
        else if(str == "all")
        {
            for(int i = 1; i <= 20; i++)
                s.insert(i);
        }
        else
        {
            s.clear();
        }
    }
}