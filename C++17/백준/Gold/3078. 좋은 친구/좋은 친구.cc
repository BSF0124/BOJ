#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> names(n);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        names[i] = str.size();
    }

    long long ans = 0;
    int start = 0, end = 0;
    vector<int> cnt(21, 0);
    while(end < n)
    {
        ans += cnt[names[end]];
        cnt[names[end]]++;

        if(end - start == k)
        {
            cnt[names[start]]--;
            start++;
        }
        end++;
    }

    cout << ans;
}