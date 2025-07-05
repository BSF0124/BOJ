#include <bits/stdc++.h>
using namespace std;

int n, q, tmp, pre = 0;
int a[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        int cur = tmp + i - 1;
        pre = max(pre, cur);
        a[i] = pre;
    }
    
    cin >> q;
    while(q--)
    {
        cin >> tmp;
        int* ans = lower_bound(a+1, a+1+n, tmp);
        cout << (ans - a) << ' ';
    }
}