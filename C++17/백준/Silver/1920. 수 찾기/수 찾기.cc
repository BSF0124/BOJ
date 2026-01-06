#include <bits/stdc++.h>
using namespace std;

int n, m, tmp;
int st, mid, en;
int arr[100002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    
    cin >> m;
    while(m--)
    {
        st = 0;
        en = n-1;
        
        cin >> tmp;
        while(st <= en)
        {
            mid = (st+en)/2;

            if(tmp > arr[mid]) 
                st = mid+1;
            else if(tmp < arr[mid]) 
                en = mid - 1;
            else 
                break;
        }
        cout << (tmp == arr[mid]) << '\n';
    }
}