#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
            cout << 'G';
        for(int j = 0; j < 3*k; j++)
            cout << '.';
        cout << '\n';
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
            cout << '.';
        for(int j = 0; j < k; j++)
            cout << 'I';
        for(int j = 0; j < k; j++)
            cout << '.';
        for(int j = 0; j < k; j++)
            cout << 'T';
        cout << '\n';
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < 2*k; j++)
            cout << '.';
        for(int j = 0; j < k; j++)
            cout << 'S';
            for(int j = 0; j < k; j++)
            cout << '.';
        cout << '\n';
    }
}