#include <bits/stdc++.h>
using namespace std;

int n, tmp;
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int>> mn;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> tmp;
        if(mx.size() <= mn.size()) mx.push(tmp);
        else mn.push(tmp);

        if(!mn.empty() && mn.top() < mx.top())
        {
            mn.push(mx.top());
            mx.pop();
            mx.push(mn.top());
            mn.pop();
        }
        cout << mx.top() << '\n';
    }
}