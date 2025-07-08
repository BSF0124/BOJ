#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) cin >> cnt[i];
    
    unordered_map<int, int> m;
    int mx = 0, st = 0, en = 0;

    while(en < n)
    {
        m[cnt[en]]++;

        while(m.size() > 2)
        {
            m[cnt[st]]--;
            if(m[cnt[st]] == 0) m.erase(cnt[st]);
            st++;
        }

        mx = max(mx, en - st + 1);
        en++;
    }

    cout << mx;
}