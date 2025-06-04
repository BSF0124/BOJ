#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[1000002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int st, en;
        cin >> st >> en;
        for(int j = st; j < en; j++) arr[j]++;
    }

    int a = 0, b = 0, sum = arr[0];
    while(a < 1000000)
    {
        while(b < 1000000 && sum < k)
        {
            b++;
            if(b != 1000000) sum += arr[b];
        }

        if(b == 1000000) break;

        if(sum == k)
        {
            cout << a << ' ' << b+1;
            return 0;
        }

        sum -= arr[a++];
    }
    cout << "0 0";
}