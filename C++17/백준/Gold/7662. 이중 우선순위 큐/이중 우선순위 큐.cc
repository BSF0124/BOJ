#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        multiset<int> ms;
        int k;
        cin >> k;
        while(k--)
        {
            char ch;
            int n;
            cin >> ch >> n;
            if(ch == 'I')
                ms.insert(n);
            else
            {
                if(ms.empty()) continue;
                else if(n == 1) ms.erase(prev(ms.end()));
                else ms.erase(ms.begin());
            }
        }
        if(ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }
}