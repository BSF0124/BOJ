#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int ans = 1;

    cin >> str;
    for(char ch : str)
        if(ch == ',') ans++;

    cout << ans;
}