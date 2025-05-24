#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if(v.empty() || tmp > v.back()) v.push_back(tmp);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), tmp) - v.begin();
            v[idx] = tmp;
        }
    }
    cout << v.size();
}