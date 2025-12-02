#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    for(char ch : str)
    {
        if(ch >= 97)
            cout << (char)(ch-32);
        else
            cout << (char)(ch+32);
    }
    return 0;
}