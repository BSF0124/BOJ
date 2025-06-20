#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long ans = 0;
        cin >> n;
        while(n--)
        {
            long long tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        while(pq.size() != 1)
        {
            long long tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();

            ans += tmp;
            pq.push(tmp);
        }
        cout << ans << '\n';
    }
}