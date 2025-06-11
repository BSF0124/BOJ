#include <bits/stdc++.h>
using namespace std;

string comm;
int n,m,p,l,x;
int level[100002];
set<int> prob[102];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> p >> l;
        level[p] = l;
        prob[l].insert(p);
    }

    cin >> m;
    while(m--)
    {
        cin >> comm;
        if(comm == "recommend")
        {
            cin >> x;
            if(x == 1)
            {
                for(int i = 100; i >= 1; i--)
                {
                    if(prob[i].empty()) continue;
                    cout << *(prev(prob[i].end())) << '\n';
                    break;
                }
            }
            else
            {
                for(int i = 1; i <= 100; i++)
                {
                    if(prob[i].empty()) continue;
                    cout << *prob[i].begin() << '\n';
                    break;
                }
            }
        }
        else if(comm == "add")
        {
            cin >> p >> l;
            level[p] = l;
            prob[l].insert(p);
        }
        else
        {
            cin >> p;
            prob[level[p]].erase(p);
        }
    }
}