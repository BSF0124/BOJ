#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    int arr[30];
    fill(arr, arr+30, 0);

    for(char c : str)
    {
        int num = c - 'a';
        arr[num]++;
    }

    for(int i = 0 ; i < 26; i++)
        cout << arr[i] << ' ';
}