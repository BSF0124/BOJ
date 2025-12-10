#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m, ans = 0;
string board[602];
bool vis[602][602];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int>> S;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'I')
            {
                S.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    while(!S.empty())
    {
        auto cur = S.top(); S.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || board[nx][ny] == 'X') continue;

            if(board[nx][ny] == 'P') ans++;
            vis[nx][ny] = 1;
            S.push({nx,ny});
        }
    }

    if(!ans) cout << "TT";
    else cout << ans;
}