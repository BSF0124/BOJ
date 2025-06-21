#include <bits/stdc++.h>
using namespace std;

vector<int> swift;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    swift.push_back(0);

    int n, tmp;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        swift.push_back(swift[i-1] + tmp);
    }

    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum += tmp;
        if(sum == swift[i]) ans = i;
    }
    cout << ans;
}