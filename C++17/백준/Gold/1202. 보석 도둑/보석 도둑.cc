#include <bits/stdc++.h>
using namespace std;

int n, k, c;
pair<int,int> gem[300002];
multiset<int> bag;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> gem[i].second >> gem[i].first;
    sort(gem, gem+n);

    for(int i = 0; i < k; i++)
    {
        cin >> c;
        bag.insert(c);
    }

    long long ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(bag.lower_bound(gem[i].second) == bag.end()) continue;
        ans += gem[i].first;
        bag.erase(bag.lower_bound(gem[i].second));
    }

    cout << ans;
}