#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100002];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, ans_st = 0;
    int en = n-1, ans_en = n-1;
    int tmp = INT_MAX;

    while(st < en)
    {
        int sum = arr[st] + arr[en];
        if(abs(sum) < tmp)
        {
            tmp = abs(sum);
            ans_st = st;
            ans_en = en;
        }

        if(sum < 0) st++;
        else en--;
    }

    cout << arr[ans_st] << ' ' << arr[ans_en];
}
