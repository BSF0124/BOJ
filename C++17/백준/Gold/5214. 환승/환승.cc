#include <bits/stdc++.h>
using namespace std;

int n, k, m, tmp;
vector<int> hyp[1002];
vector<int> sta[100002];
int dist[100002] = {};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < k; j++)
        {
            int tmp;
            cin >> tmp;
            hyp[i].push_back(tmp);
            sta[tmp].push_back(i);
        }
    }

    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        for(auto tube : sta[cur])
        {
            for(auto nxt : hyp[tube])
            {
                if(dist[nxt] > 0) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }

    cout << (dist[n] == 0 ? -1 : dist[n]);
}