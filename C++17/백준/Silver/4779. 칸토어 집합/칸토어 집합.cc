#include <bits/stdc++.h> 
using namespace std;

int n;

string func(int num)
{
    if(num == 0) return "-";
    string str = func(num - 1);
    string space(pow(3, num-1), ' ');
    string _str = str + space + str;
    return _str;
}

void func(string &s, int st, int len)
{
    if(len == 1) return;

    int tmp = len / 3;

    for(int i = st+tmp; i < st+2*tmp; i++)
        s[i] = ' ';
    
    func(s, st, tmp);
    func(s, st+2*tmp, tmp);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin >> n)
    {
        int len = pow(3,n);
        string s(len, '-');
        func(s,0,len);
        cout << s << '\n';
    }
}