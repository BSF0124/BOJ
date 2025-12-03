#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    queue<int> q;
    for(int i = 1; i <= n; i++)
        q.push(i);

    vector<int> ans;

    while(!q.empty())
    {
        ans.push_back(q.front());
        q.pop();

        q.push(q.front());
        q.pop();
    }

    for(auto i : ans)
        cout << i << ' ';
}