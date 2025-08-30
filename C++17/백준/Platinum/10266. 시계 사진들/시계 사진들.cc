#include <bits/stdc++.h>
using namespace std;

int a[200002], b[200002];
int n;

vector<int> failure()
{
    vector<int> f(n);
    for(int i = 1, j = 0; i < n; i++)
    {
        while(j > 0 && a[i] != a[j]) j = f[j-1];
        if(a[i] == a[j]) f[i] = ++j;
    }
    return f;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    a[n] = a[0] + 360000;
    b[n] = b[0] + 360000;

    for(int i = 0; i < n; i++)
    {
        a[i] = a[i+1] - a[i];
        b[i] = b[i+1] - b[i];
    }

    vector<int> f = failure();
    for(int i = 0, j = 0; i < 2*n-1; i++)
    {
        int ci = i % n;
        while(j > 0 && b[ci] != a[j]) j = f[j-1];
        if(b[ci] == a[j]) j++;
        if(j == n)
        {
            cout << "possible";
            return 0;
        }
    }
    cout << "impossible";
}