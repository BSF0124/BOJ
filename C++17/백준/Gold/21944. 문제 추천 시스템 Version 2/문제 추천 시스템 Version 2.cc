#include <bits/stdc++.h>
using namespace std;

string comm;
int n,m,p,l,x,g;
pair<int,int> level[100002];
set<int> prob[102];
set<int> prob2[102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        cin >> p >> l >> g;
        level[p] = {l,g};
        prob[l].insert(p);
        prob2[l][g].insert(p);
    }

    cin >> m;
    while(m--)
    {
        cin >> comm;
        if(comm == "recommend")
        {
            cin >> g >> x;
            if(x == 1)
            {
                for(int i = 100; i >= 1; i--)
                {
                    if(prob2[i][g].empty()) continue;
                    cout << *(prev(prob2[i][g].end())) << '\n';
                    break;
                }
            }
            else
            {
                for(int i = 1; i <= 100; i++)
                {
                    if(prob2[i][g].empty()) continue;
                    cout << *prob2[i][g].begin() << '\n';
                    break;
                }
            }
        }
        else if(comm == "recommend2")
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
        else if(comm == "recommend3")
        {
            cin >> x >> l;
            int tmp = -1;
            if(x == 1)
            {
                for(int i = l; i <= 100; i++)
                {
                    if(prob[i].empty()) continue;
                    tmp = *prob[i].begin();
                    break;
                }
            }
            else
            {
                for(int i = l-1; i >= 1; i--)
                {
                    if(prob[i].empty()) continue;
                    tmp = *(prev(prob[i].end()));
                    break;
                }
            }
            cout << tmp << '\n';
        }
        else if(comm == "add")
        {
            cin >> p >> l >> g;
            level[p] = {l,g};
            prob[l].insert(p);
            prob2[l][g].insert(p);
        }
        else
        {
            cin >> p;
            prob[level[p].first].erase(p);
            prob2[level[p].first][level[p].second].erase(p);
        }
    }
}