#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, int> h;
string names[100005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> names[i];
        h[names[i]] = i;
    }

    while(m--)
    {
        string str;
        cin >> str;
        if(isdigit(str[0])) cout << names[stoi(str)] << '\n';
        else cout << h[str] << '\n';
    }
}