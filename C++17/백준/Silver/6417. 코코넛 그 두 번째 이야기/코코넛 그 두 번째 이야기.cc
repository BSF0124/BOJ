#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        cin >> n;
        if(n == -1) return 0;

        vector<int> v;
        for(int i = 2; i <= n; i++)
        {
            bool chk = 1;
            int tmp = n;
            for(int j = 0; j < i; j++)
            {
                tmp--;
                if(tmp % i != 0)
                {
                    chk = 0;
                    break;
                }
                tmp -= tmp / i;
            }
            if(tmp % i != 0) chk = 0;

            if(chk) v.push_back(i);
        }

        if(v.empty())
            cout << n << " coconuts, no solution\n";
        else
            cout << n << " coconuts, " << v.back() << " people and 1 monkey\n";
    }
}