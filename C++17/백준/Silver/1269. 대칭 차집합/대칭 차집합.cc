#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_set<int> s;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n+m; i++)
    {
        int num;
        cin >> num;

        if(s.find(num) == s.end()) s.insert(num);
        else s.erase(num);
    }

    cout << s.size();
}