#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin >> n;
    while(n--)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int st = 0, en = v.size()-1, mn = INT_MAX;
    int ans1, ans2;

    while(st < en)
    {
        int sum = v[st] + v[en];
        if(abs(sum) < mn)
        {
            mn = abs(sum);
            ans1 = v[st];
            ans2 = v[en];
        }

        if(sum > 0) en--;
        else st++;
    }

    cout << ans1 << ' ' << ans2;
}