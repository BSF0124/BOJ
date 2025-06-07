#include <bits/stdc++.h>
using namespace std;

string s, e, q;
unordered_set<string> h;

int sToi(string time)
{
    return (time[0]-'0')*600 + (time[1]-'0')*60 + (time[3]-'0') * 10 + (time[4]-'0');
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> e >> q;

    int ans = 0;
    while(1)
    {
        string time, id;
        cin >> time >> id;
        if(cin.eof() == true) break;

        if(sToi(time) <= sToi(s))
        {
            h.insert(id);
        }
        else if(sToi(time) >= sToi(e) && sToi(time) <= sToi(q))
        {
            if(h.find(id) != h.end())
            {
                ans++;
                h.erase(id);
            }
        }
    }
    cout << ans;
}