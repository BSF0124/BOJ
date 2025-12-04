#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<pair<int,int>> dq;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        dq.push_back({i+1, num});
    }

    while(!dq.empty())
    {
        auto balloon = dq.front();
        dq.pop_front();

        cout << balloon.first << ' ';
        if(dq.empty()) return 0;

        if(balloon.second > 0)
        {
            for(int i = 0; i < balloon.second-1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            for(int i = 0; i > balloon.second; i--)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}