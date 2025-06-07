#include <bits/stdc++.h>
using namespace std;

string str;
unordered_set<string> s;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for(int i = 0; i < str.size(); i++)
        for(int j = 1; j <= str.size(); j++)
            s.insert(str.substr(i,j));
    
    cout << s.size();
}