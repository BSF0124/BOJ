#include <bits/stdc++.h> 
using namespace std;

int t, cnt;
string str;

int recursion(const string& str, int l, int r)
{
    cnt++;
    if(l >= r) return 1;
    if(str[l] != str[r]) return 0;
    return recursion(str, l+1, r-1);
}

int isPalindrome(const string& str)
{
    return recursion(str, 0, str.size()-1);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> str;
        cnt = 0;
        cout << isPalindrome(str) << ' ' << cnt << '\n';
    }
}