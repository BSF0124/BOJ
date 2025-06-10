#include <bits/stdc++.h>
using namespace std;

int t,k,n;
char ch;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        multiset<int> ms;
        cin >> k;
        while(k--)
        {
            cin >> ch >> n;
            if(ch == 'I') ms.insert(n);
            else
            {
                if(ms.empty()) continue;
                if(n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
}