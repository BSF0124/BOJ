#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
char b;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;
    for(int i = 0; i < n*4; i++)
    {
        string str;
        cin >> str;
        switch(str[0])
        {
            case 'A':
                ans += 11;
                break;
            case 'K':
                ans += 4;
                break;
            case 'Q':
                ans += 3;
                break;
            case 'J':
                ans += (str[1] == b) ? 20 : 2;
                break;
            case 'T':
                ans += 10;
                break;
            case '9':
                if(str[1] == b) ans += 14;
                break;
            case '8':
            case '7':
                break;
        }
    }
    cout << ans;
}