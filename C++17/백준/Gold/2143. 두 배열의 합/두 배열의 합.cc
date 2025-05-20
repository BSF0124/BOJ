#include <bits/stdc++.h>
using namespace std;

int n,m,t;
long long a[1002], b[1002];
vector<long long> a_sum,b_sum;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    // a의 부분합 저장
    for(int i = 0; i < n; i++)
    {
        long long sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += a[j];
            a_sum.push_back(sum);
        }
    }

    // b의 부분합 저장
    for(int i = 0; i < m; i++)
    {
        long long sum = 0;
        for(int j = i; j < m; j++)
        {
            sum += b[j];
            b_sum.push_back(sum);
        }
    }

    sort(b_sum.begin(), b_sum.end());
    long long cnt = 0;
    for(auto i : a_sum)
    {
        auto ub = upper_bound(b_sum.begin(), b_sum.end(), t-i);
        auto lb = lower_bound(b_sum.begin(), b_sum.end(), t-i);
        cnt += ub-lb;
    }
    cout << cnt;
}