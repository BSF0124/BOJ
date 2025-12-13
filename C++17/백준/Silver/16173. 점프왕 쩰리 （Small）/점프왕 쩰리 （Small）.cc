#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second
int dx[2] = {0,1};
int dy[2] = {1,0};

int n;
int board[3][3];
bool vis[3][3];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    stack<pair<int,int>> S;
    S.push({0,0});
    vis[0][0] = 1;

    while(!S.empty())
    {
        auto cur = S.top(); S.pop();

        if(board[cur.X][cur.Y] == -1)
        {
            cout << "HaruHaru";
            return 0;
        }

        for(int dir = 0; dir < 2; dir++)
        {
            int nx = cur.X + dx[dir] * board[cur.X][cur.Y];
            int ny = cur.Y + dy[dir] * board[cur.X][cur.Y];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = 1;
            S.push({nx,ny});
        }
    }

    cout << "Hing";
}