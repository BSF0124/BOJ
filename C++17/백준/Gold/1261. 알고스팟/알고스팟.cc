#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;
bool board[102][102];
int dist[102][102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            board[i][j] = (str[j] == '1');
            dist[i][j] = INT_MAX;
        }
    }

    dist[0][0] = 0;
    deque<pair<int,int>> dq;
    dq.emplace_front(0,0);
    while(!dq.empty())
    {
        auto cur = dq.front(); dq.pop_front();
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            int tmp = board[nx][ny] ? 1 : 0;
            if(dist[nx][ny] > dist[cur.X][cur.Y] + tmp)
            {
                dist[nx][ny] = dist[cur.X][cur.Y] + tmp;
                if(tmp == 0) dq.emplace_front(nx,ny);
                else dq.emplace_back(nx,ny);
            }
        }
    }

    cout << dist[n-1][m-1];
}