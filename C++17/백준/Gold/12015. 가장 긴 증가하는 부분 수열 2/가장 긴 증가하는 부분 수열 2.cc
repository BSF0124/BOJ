#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> lis;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if(lis.empty() || num > lis.back()) 
            lis.push_back(num);
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
            lis[idx] = num;
        }
    }
    cout << lis.size();
}
