#include <bits/stdc++.h>
using namespace std;

int n;
int arr[5002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    long long tmp = LLONG_MAX;
    int ans = 0, ans_st = 1, ans_en = n-1;
    for(int i = 0; i < n-2; i++)
    {
        int st = i+1, en = n-1;
        while(st < en)
        {
            long long sum = 1LL * arr[i] + arr[st] + arr[en];

            if(abs(sum) < abs(tmp))
            {
                tmp = sum;
                ans = i;
                ans_st = st;
                ans_en = en;
            }

            if(sum > 0) en--;
            else st++;
        }
    }
    cout << arr[ans] << ' ' << arr[ans_st] << ' ' << arr[ans_en];
}