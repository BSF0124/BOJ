#include <bits/stdc++.h>
using namespace std;

int n, rm, root, ans = 0;
vector<int> adj[52];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp != -1) adj[tmp].push_back(i);
        else root = i;
    }

    cin >> rm;

    if(root != rm)
    {
        queue<int> q;
        q.push(root);
        while(!q.empty())
        {
            int cur = q.front(); q.pop();

            bool chk = 1;
            for(auto nxt : adj[cur])
            {
                if(nxt == rm) continue;
                q.push(nxt);
                chk = 0;
            }
            ans += chk;
        }
    }

    cout << ans;
}