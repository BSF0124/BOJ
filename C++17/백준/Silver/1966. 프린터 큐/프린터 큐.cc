#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        int cnt = 0;
        queue<pair<int,int>> q;
        priority_queue<int> printer;

        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            q.push({i,tmp});
            printer.push(tmp);
        }

        while(!printer.empty())
        {
            int idx = q.front().first;
            int prior = q.front().second;
            q.pop();

            if(printer.top() == prior)
            {
                cnt++;
                printer.pop();
                if(idx == m)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
                q.push({idx, prior});
        }
    }
}