#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int sum = 0, x = -1;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '*')
        {
            x = i;
            continue;
        }

        int tmp = str[i] - '0';
        sum += (i % 2 == 0) ? tmp : tmp * 3;
    }

    for(int i = 0; i < 10; i++)
    {
        int tmp = sum + ((x % 2 == 0) ? i : i * 3);
        if(tmp % 10 == 0)
            cout << i;
    }
}