#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int n, num;
    cin >> n;

    while(1)
    {
        cin >> num;

        if(num == -1) break;
        
        else if(num == 0) q.pop();
        
        else if(q.size() < n) q.push(num);
    }
    

    if(q.empty()) cout << "empty";
    else
    {
        while(!q.empty())
        {
            cout << q.front() << ' ';
            q.pop();
        }
    }
}