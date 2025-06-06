#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string> pwlist;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(n--)
    {
        string url, pwd;
        cin >> url >> pwd;
        pwlist.insert({url, pwd});
    }

    while(m--)
    {
        string url;
        cin >> url;
        cout << pwlist[url] << '\n';
    }
}