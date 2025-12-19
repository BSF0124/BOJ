#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, ans = 1;
    cin >> a >> b >> c;

    vector<int> v;
    if(a % 2 == 1) v.push_back(a);
    if(b % 2 == 1) v.push_back(b);
    if(c % 2 == 1) v.push_back(c);

    if(v.empty())
    {
        cout << a*b*c;
        return 0;
    }

    for(auto e : v)
        ans *= e;
    cout << ans;
}