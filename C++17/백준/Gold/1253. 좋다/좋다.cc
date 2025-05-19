#include <bits/stdc++.h>
using namespace std;

int n;
int arr[2002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int st = 0, en = n-1;
        while(st < en)
        {
            if(st == i)
            {
                st++;
                continue;
            }
            else if(en == i)
            {
                en--;
                continue;
            }

            int sum = arr[st] + arr[en];
            if(sum == arr[i])
            {
                cnt++;
                break;
            }
            
            if(sum > arr[i]) en--;
            else st++;
        }
    }

    cout << cnt;
}