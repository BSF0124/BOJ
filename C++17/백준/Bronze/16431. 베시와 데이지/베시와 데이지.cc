#include <bits/stdc++.h>
using namespace std;

int br, bc, dr, dc, jr, jc;
int bessie, daisy;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> br >> bc >> dr >> dc >> jr >> jc;

    br = abs(jr - br);
    bc = abs(jc - bc);
    bessie = max(br, bc);
    
    daisy = abs(jr - dr) + abs(jc - dc);

    if(bessie == daisy) cout << "tie";
    else if(bessie < daisy) cout << "bessie";
    else cout << "daisy";
}