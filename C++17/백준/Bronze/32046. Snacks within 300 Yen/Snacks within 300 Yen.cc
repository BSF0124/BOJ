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
        if(n == 0) return 0;

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if(sum + tmp <= 300) sum += tmp;
        }

        cout << sum << '\n';
    }
}