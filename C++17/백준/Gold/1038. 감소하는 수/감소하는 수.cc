#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v;
    for(int i = 1; i < 1024; i++)
    {
        string s = "";

        for(int digit = 9; digit >= 0; digit--)
            if(i & (1 << digit))
                s.push_back('0' + digit);

        v.push_back(stoll(s));
    }
    sort(v.begin(), v.end());

    if(n >= v.size()) 
        cout << -1;
    else 
        cout << v[n];
}