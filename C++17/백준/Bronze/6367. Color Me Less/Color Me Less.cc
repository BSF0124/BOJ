#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> rgb;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 16; i++)
    {
        int r,g,b;
        cin >> r >> g >> b;
        rgb.push_back({r,g,b});
    }

    while(1)
    {
        int r,g,b;
        int ans, mn = INT_MAX;
        cin >> r >> g >> b;
        if(r == -1 && g == -1 && b == -1) return 0;

        for(int i = 0; i < 16; i++)
        {
            int d = pow(r - get<0>(rgb[i]), 2) + pow(g - get<1>(rgb[i]), 2) + pow(b - get<2>(rgb[i]), 2);
            if(d < mn)
            {
                mn = d;
                ans = i;
            }
        }

        cout << '(' << r << ',' << g << ',' << b << ") maps to (";
        tie(r,g,b) = rgb[ans];
        cout << r << ',' <<g << ',' << b << ")\n";
    }
}