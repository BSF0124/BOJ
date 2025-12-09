#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<int> L;
    int n, k;

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        L.push_back(i);

    auto t = L.begin();
    cout << '<';
    while(L.size() > 1)
    {
        for(int i = 1; i < k; i++)
        {
            t++;
            if(t == L.end()) t = L.begin();
        }

        cout << *t << ", ";
        t = L.erase(t);

        if(t == L.end()) t = L.begin();
    }
    cout << *t << '>';
    return 0;
}