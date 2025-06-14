#include <bits/stdc++.h>
using namespace std;

int n;
bool board[52][10][10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int mn = INT_MAX, a, b;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 7; k++)
            {
                char ch;
                cin >> ch;
                board[i][j][k] = (ch == 'X');
            }
        }
    }

    for(int i = 1; i <= n-1; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            int cnt = 0;

            for(int x = 0; x < 5; x++)
                for(int y = 0; y < 7; y++)
                    if(board[i][x][y] != board[j][x][y]) cnt++;
            
            if(mn > cnt)
            {
                mn = cnt;
                a = i;
                b = j;
            }
        }
    }

    cout << a << ' ' << b;
}