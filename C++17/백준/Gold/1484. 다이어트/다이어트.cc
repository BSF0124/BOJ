#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ans;
    long long st = 1, en = 1, g;
    cin >> g;

    while(en*en - (en-1)*(en-1) <= g)
    {
        long long diff = en*en - st*st;

        if(diff == g) 
        {
            ans.push_back(en);
            en++;
        }

        else if(diff < g) 
            en++;
        else 
            st++;

        if(st >= en)
            en = st+1;
    }

    if(ans.empty())
    {
        cout << -1;
        return 0;
    }

    for(auto e : ans)
        cout << e << '\n';
}