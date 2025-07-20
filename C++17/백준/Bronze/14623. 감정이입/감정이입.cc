#include <bits/stdc++.h>
using namespace std;

long long Binary_To_Decimal(const string& s)
{
    long long res = 0;

    for(char c : s)
        res = (res << 1) + (c - '0');
    
    return res;
}

string Decimal_To_Binary(long long n)
{
    if(n == 0) return "0";

    string res;
    while(n > 0)
    {
        res.push_back(char('0' + (n & 1)));
        n >>= 1;
    }

    reverse(res.begin(), res.end());
    return res;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string b1, b2;
    cin >> b1 >> b2;
    long long ans = Binary_To_Decimal(b1) * Binary_To_Decimal(b2);
    cout << Decimal_To_Binary(ans);
}
