#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0;
int a[10002];

int insertion_sort()
{
    for(int i = 2; i <= n; i++)
    {
        int cur = i - 1;
        int tmp = a[i];

        while(cur >= 1 && tmp < a[cur])
        {
            a[cur+1] = a[cur];
            if(++cnt == k) return a[cur];
            cur--;
        }

        if(cur+1 != i)
        {
            a[cur+1] = tmp;
            if(++cnt == k) return tmp;
        }
    }

    return -1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cout << insertion_sort();
}