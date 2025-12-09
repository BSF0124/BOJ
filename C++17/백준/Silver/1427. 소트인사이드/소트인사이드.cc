#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int cnt[10] = {};
    for(char ch : str)
    {
        int num = (ch - '0');
        cnt[num]++;
    }

    for(int i = 9; i >= 0; i--)
        for(int j = 0; j < cnt[i]; j++)
            cout << i;
}