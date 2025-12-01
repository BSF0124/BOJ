#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[10] = {0};

    while(n > 0)
    {
        int num = n%10;
        arr[num]++;
        n /= 10;
    }

    int tmp = arr[6] + arr[9];
    arr[6] = (tmp+1) / 2;
    arr[9] = 0;

    cout << *max_element(arr, arr+10);
}