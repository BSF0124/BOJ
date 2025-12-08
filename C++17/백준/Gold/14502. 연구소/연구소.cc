#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;
int board[10][10];

int bfs()
{
    queue<pair<int,int>> Q;
    bool vis[10][10] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 2)
            {
                Q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    while(!Q.empty())
    {
        auto cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        } 
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0 && !vis[i][j]) cnt++;
        
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int,int>> combos;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0) combos.push_back({i,j});
        }
    }

    int tmp = combos.size();
    int ans = 0;
    for(int i = 0; i < tmp-2; i++)
    {
        board[combos[i].X][combos[i].Y] = 1;
        for(int j = i+1; j < tmp-1; j++)
        {
            board[combos[j].X][combos[j].Y] = 1;
            for(int k = j+1; k < tmp; k++)
            {
                board[combos[k].X][combos[k].Y] = 1;
                ans = max(ans, bfs());
                board[combos[k].X][combos[k].Y] = 0;
            }
            board[combos[j].X][combos[j].Y] = 0;
        }
        board[combos[i].X][combos[i].Y] = 0;
    }

    cout << ans;
}