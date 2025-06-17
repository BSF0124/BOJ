#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    cout << arr.front() * arr.back();
}