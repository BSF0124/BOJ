#include <bits/stdc++.h> 
using namespace std;

int n;
map<string, int> cnt;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string str;
    while(n--)
    {
        cin >> str;
        int idx = str.find('.');
        string name = str.substr(0, idx);
        string ext = str.substr(idx+1);
        cnt[ext]++;
    }

    for(auto &e : cnt)
        cout << e.first << ' ' << e.second << '\n';
}