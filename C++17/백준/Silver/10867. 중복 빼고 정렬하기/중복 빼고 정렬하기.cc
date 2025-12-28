#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    bool arr[2002] = {};

    cin >> n;
    while(n--)
    {
        int num;
        cin >> num;
        arr[num+1000] = 1;
    }

    for(int i = 0; i <= 2000; i++)
        if(arr[i]) cout << i-1000 << ' ';
}