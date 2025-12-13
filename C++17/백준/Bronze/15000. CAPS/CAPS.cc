#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for(char &ch : str)
        ch = ch - 32;

    cout << str;
}