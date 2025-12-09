#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d,e,f,x,y;
    cin >> a >> b >> c >> d >> e >> f;

    if(b*d-a*e == 0)
    {
        x = (c*d - b*f) / (a*e - b*d);

        if(b == 0)
            y = (f-e*y) / d;
        else 
            y = (c-a*x) / b;
    }
    else
    {
        y = (c*d - a*f) / (b*d - a*e);

        if(a == 0) 
            x = (f-e*y) / d;
        else 
            x = (c-b*y) / a;
    }

    cout << x << ' ' << y;
}