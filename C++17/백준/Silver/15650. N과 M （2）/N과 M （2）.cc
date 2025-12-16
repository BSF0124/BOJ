#include <bits/stdc++.h>
using namespace std;

int arr[10];
int n, m;

void Combination(int k)
{
    if(k == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st = 1;
    if(k != 0) st = arr[k-1] + 1;
    for(int i = st; i <= n; i++)
    {
        arr[k] = i;
        Combination(k + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    Combination(0);
}