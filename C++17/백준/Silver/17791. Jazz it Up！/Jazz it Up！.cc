#include <bits/stdc++.h>
using namespace std;

int n;

bool func(int num)
{
    for(int i = 2; i*i <= num; i++)
    {
        if(num % (i*i) == 0)
            return 0;
    }
    return 1;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int m = 2; m < n; m++)
    {
        if(func(n*m))
        {
            cout << m;
            return 0;
        }
    }
}