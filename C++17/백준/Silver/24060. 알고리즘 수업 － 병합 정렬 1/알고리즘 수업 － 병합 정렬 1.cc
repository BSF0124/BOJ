#include <bits/stdc++.h> 
using namespace std;

int n, ans = -1;
long long k, cnt = 0;
int arr[500000];
int tmp[500000];

void merge(int st, int mid, int en)
{
    int i = st;
    int j = mid + 1;
    int t = 0;

    while (i <= mid && j <= en)
    {
        if (arr[i] <= arr[j]) 
            tmp[t++] = arr[i++];
        else 
            tmp[t++] = arr[j++];
    }

    while (i <= mid) 
        tmp[t++] = arr[i++];
    while (j <= en)  
        tmp[t++] = arr[j++];

    i = st;
    t = 0;

    while (i <= en)
    {
        arr[i] = tmp[t++];
        cnt++;
        if (cnt == k)
            ans = arr[i];
        i++;
    }
}

void merge_sort(int st, int en)
{
    if(st >= en) return;

    int mid = (st+en) / 2;
    merge_sort(st, mid);
    merge_sort(mid+1, en);
    merge(st,mid,en);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(0, n-1);
    cout << ans;
}