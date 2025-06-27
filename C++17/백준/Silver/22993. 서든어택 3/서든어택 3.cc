#include <bits/stdc++.h>
using namespace std;

int n;
long long jw;
vector<long long> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> jw;
    while(--n)
    {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
    {
        if(jw > v[i]) 
            jw += v[i];
        else
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}