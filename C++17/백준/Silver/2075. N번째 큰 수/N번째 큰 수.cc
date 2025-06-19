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
    for(int i = 0; i < n*n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
        if(pq.size() > n)
            pq.pop();
    }
    
    cout << pq.top();
}