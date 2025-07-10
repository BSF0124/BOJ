#include <bits/stdc++.h>
using namespace std;

int n,r,q;
vector<int> adj[100002];
vector<int> child[100002];
int parent[100002];
int cnt[100002];

void makeTree(int cur, int par)
{
    for(auto nxt : adj[cur])
    {
        if(par != nxt)
        {
            parent[nxt] = cur;
            child[cur].push_back(nxt);
            makeTree(nxt, cur);
        }
    }
}

void countSubtreeNodes(int cur)
{
    cnt[cur] = 1;
    for(auto nxt : child[cur])
    {
        countSubtreeNodes(nxt);
        cnt[cur] += cnt[nxt];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;
    while(--n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    makeTree(r,0);
    countSubtreeNodes(r);

    while(q--)
    {
        int tmp;
        cin >> tmp;
        cout << cnt[tmp] << '\n';
    }
}