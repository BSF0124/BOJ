#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> v;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
    return a.second < b.second;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            v.push_back({i,tmp});
        }
    }
    sort(v.begin(), v.end(), cmp);

    int cnt[1002] = {};
    int en = 0, mn = INT_MAX, unique_class = 0;
    for(int st = 0; st < v.size(); st++)
    {
        while(en < v.size() && unique_class < n)
        {
            if(cnt[v[en].first]++ == 0) unique_class++;
            en++;
        }
        if(unique_class == n)
        {
            mn = min(mn, v[en-1].second - v[st].second);
        }

        if(--cnt[v[st].first] == 0) unique_class--;
    }

    cout << mn;
}