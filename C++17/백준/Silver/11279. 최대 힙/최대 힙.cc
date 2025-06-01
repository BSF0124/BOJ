#include <bits/stdc++.h>
using namespace std;

int n, tmp;
priority_queue<int, vector<int>> heap;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--)
    {
        cin >> tmp;

        if(tmp == 0)
        {
            if(heap.empty()) cout << 0 << '\n';
            else
            {
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
        else heap.push(tmp);
    }
}