#include <bits/stdc++.h>
using namespace std;

int n, q;
int tmp,i,x;
set<int> s;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        if(tmp) s.insert(i);
    }

    int cur = 1;
    while(q--)
    {
        cin >> tmp;
        if(tmp == 1)
        {
            cin >> i;
            if(s.find(i) != s.end()) s.erase(i);
            else s.insert(i);
        }
        else if(tmp == 2)
        {
            cin >> x;
            cur = (cur + x) % n;
            if(cur == 0) cur = n;
        }
        else 
        {
            if(s.empty()) 
                cout << -1 << '\n';
            else
            {
                auto it = s.lower_bound(cur);
                if(it != s.end()) cout << *it - cur << '\n';
                else cout << n - cur + *s.begin() << '\n';
            }
        }
    }
}