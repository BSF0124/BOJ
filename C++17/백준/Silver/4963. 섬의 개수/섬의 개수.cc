#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

int w, h;
bool board[52][52];
bool vis[52][52];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        cin >> h >> w;
        if(w == 0 && h == 0) return 0;

        queue<pair<int,int>> Q;
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                cin >> board[i][j];
                vis[i][j] = 0;
            }
        }

        int ans = 0;
        for(int i = 0; i < w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                if(!board[i][j] || vis[i][j]) continue;

                Q.push({i,j});
                vis[i][j] = 1;
                ans++;

                while(!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();

                    for(int dir = 0; dir < 8; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                        if(!board[nx][ny]) continue;
                        if(vis[nx][ny]) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}