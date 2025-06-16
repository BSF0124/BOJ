#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    queue<pair<long long, int>> Q;
    Q.push({a, 1});

    while(!Q.empty())
    {
        long long cur = Q.front().first;
        int vis = Q.front().second;
        Q.pop();

        if(cur == b)
        {
            cout << vis;
            return 0;
        }

        if(cur*2 <= b) Q.push({cur*2, vis+1});
        if(cur*10+1 <= b) Q.push({cur*10+1, vis+1});
    }

    cout << -1;
}