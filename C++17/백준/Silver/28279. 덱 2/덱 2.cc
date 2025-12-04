#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;
    int n;
    cin >> n;
    while(n--)
    {
        int command, tmp;
        cin >> command;
        switch (command)
        {
            case 1:
                cin >> tmp;
                dq.push_front(tmp);
                break;

            case 2:
                cin >> tmp;
                dq.push_back(tmp);
                break;

            case 3:
                if(dq.empty()) cout << -1 << '\n';
                else
                {
                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
                break;

            case 4:
                if(dq.empty()) cout << -1 << '\n';
                else
                {
                    cout << dq.back() << '\n';
                    dq.pop_back();
                }
                break;

            case 5:
                cout << dq.size() << '\n';
                break;

            case 6:
                cout << dq.empty() << '\n';
                break;

            case 7:
                if(dq.empty()) cout << -1 << '\n';
                else cout << dq.front() << '\n';
                break;

            case 8:
                if(dq.empty()) cout << -1 << '\n';
                else cout << dq.back() << '\n';
                break;
        }
    }
}