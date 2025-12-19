#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r;
    cin >> r;

    double ans1 = r * r * M_PI;
    double ans2 = r * r * 2;

    cout << fixed << setprecision(6);
    cout << ans1 << '\n' << ans2;
}