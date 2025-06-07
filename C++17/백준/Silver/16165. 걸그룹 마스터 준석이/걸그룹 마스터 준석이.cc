#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> team;
unordered_map<string, vector<string>> member;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(n--)
    {
        string str;
        int num;
        cin >> str >> num;
        while(num--)
        {
            string name;
            cin >> name;
            team[name] = str;
            member[str].push_back(name);
        }
        sort(member[str].begin(), member[str].end());
    }

    while(m--)
    {
        string str;
        int quiz;
        cin >> str >> quiz;
        
        if(quiz) 
            cout << team[str] << '\n';
        else
            for(auto e : member[str]) cout << e << '\n';
    }
}