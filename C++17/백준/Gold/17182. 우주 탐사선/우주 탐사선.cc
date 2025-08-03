#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[12][12];
vector<int> comb;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        if(i != k) comb.push_back(i);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> d[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    int ans = INT_MAX;
    do
    {
        int tmp = d[k][comb[0]];
        for(int i = 1; i < n - 1; i++)
            tmp += d[comb[i-1]][comb[i]];
        ans = min(tmp, ans);
    } while(next_permutation(comb.begin(), comb.end()));

    cout << ans;
}