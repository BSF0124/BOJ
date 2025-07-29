#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int k, s;
    cin >> k >> s;
    k %= 26;

    getline(cin, str);
    getline(cin, str);

    for(char &ch : str)
    {
        if(isupper(ch))
            ch = char('A' + (ch - 'A' + k) % 26);
        else if(islower(ch))
            ch = char('a' + (ch - 'a' + k) % 26);
    }

    cout << str;
}
