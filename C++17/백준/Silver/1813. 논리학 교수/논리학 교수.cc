#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[52] = {0};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    for(int i = 50; i >= 0; i--)
    {
        if(cnt[i] == i)
        {
            cout << i;
            return 0;
        }
    }
    
    cout << -1;
}