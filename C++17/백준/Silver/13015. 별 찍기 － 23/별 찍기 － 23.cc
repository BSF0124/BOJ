// https://www.acmicpc.net/problem/13015
#include <bits/stdc++.h>
using namespace std;

void PrintStar(int num)
{
    for(int i = 0; i < num; i++)
        cout << '*';
}

void PrintSpace(int num)
{
    for(int i = 0; i < num; i++)
        cout << ' ';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    PrintStar(n);
    PrintSpace(2*n-3);
    PrintStar(n);
    cout << '\n';

    for(int i = 1; i <= n-2; i++)
    {
        PrintSpace(i);
        PrintStar(1);
        PrintSpace(n-2);
        PrintStar(1);
        PrintSpace(2*n-3-2*i);
        PrintStar(1);
        PrintSpace(n-2);
        PrintStar(1);
        cout << '\n';
    }

    PrintSpace(n-1);
    PrintStar(1);
    PrintSpace(n-2);
    PrintStar(1);
    PrintSpace(n-2);
    PrintStar(1);
    cout << '\n';

    for(int i = n-2; i >= 1; i--)
    {
        PrintSpace(i);
        PrintStar(1);
        PrintSpace(n-2);
        PrintStar(1);
        PrintSpace(2*n-3-2*i);
        PrintStar(1);
        PrintSpace(n-2);
        PrintStar(1);
        cout << '\n';
    }

    PrintStar(n);
    PrintSpace(2*n-3);
    PrintStar(n);
}