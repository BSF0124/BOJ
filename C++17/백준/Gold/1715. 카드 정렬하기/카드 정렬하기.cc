#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1)
    {
        int tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        ans += tmp;
    }
    cout << ans;
}