#include <bits/stdc++.h> 
using namespace std;

int n,m;
vector<int> v;

void func()
{
    if(v.size() == m)
    {
        for(auto e : v)
            cout << e << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        v.push_back(i);
        func();
        v.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func();
}