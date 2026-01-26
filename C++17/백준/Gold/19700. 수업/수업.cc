#include <bits/stdc++.h> 
using namespace std;

int n;
pair<int, int> student[500005];
multiset<int> ms;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> student[i].first >> student[i].second;
    sort(student, student+n, greater<pair<int,int>>());

    for(int i = 0; i < n; i++)
    {
        auto it = ms.lower_bound(-student[i].second + 1);
        if(it == ms.end()) ms.insert(-1);
        else
        {
            int val = *it;
            ms.erase(it);
            ms.insert(val-1);
        }
    }
    cout << ms.size();
}