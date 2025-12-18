#include <bits/stdc++.h> 
using namespace std;

int n;
vector<int> v;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    
    do
    {
        for(auto e : v)
            cout << e << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}