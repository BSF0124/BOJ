#include <bits/stdc++.h> 
using namespace std;

int ans = INT_MAX;
int board[5][5][5];
int _board[5][5][5];

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

void rotate(int idx)
{
    int tmp[5][5];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            tmp[i][j] = board[idx][4-j][i];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            board[idx][i][j] = tmp[i][j];
}

int bfs()
{
    if(board[0][0][0] == 0 || board[4][4][4] == 0)
        return -1;

    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});

    int dist[5][5][5];
    fill(&dist[0][0][0], &dist[0][0][0]+125, -1);
    dist[0][0][0] = 0;


    while(!Q.empty())
    {
        auto[z,x,y] = Q.front(); Q.pop();
        
        for(int dir = 0; dir < 6; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(dist[nz][nx][ny] != -1 || !board[nz][nx][ny]) continue;

            dist[nz][nx][ny] = dist[z][x][y] + 1;
            Q.push({nz,nx,ny});
        }
    }
    return dist[4][4][4];
}

void func()
{
    for(int b1 = 0; b1 < 4; b1++)
    {
        for(int b2 = 0; b2 < 4; b2++)
        {
            for(int b3 = 0; b3 < 4; b3++)
            {
                for(int b4 = 0; b4 < 4; b4++)
                {
                    for(int b5 = 0; b5 < 4; b5++)
                    {
                        int tmp = bfs();
                        if(tmp != -1)
                        {
                            ans = min(ans, tmp);
                            if(ans == 12) return;
                        }
                        rotate(4);
                    }
                    rotate(3);
                }
                rotate(2);
            }
            rotate(1);
        }
        rotate(0);
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                cin >> _board[i][j][k];

    int order[5] = {0,1,2,3,4};
    do
    {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                for(int k = 0; k < 5; k++)
                    board[i][j][k] = _board[order[i]][j][k];
        func();
    } while (next_permutation(order, order+5));
    
    cout << (ans == INT_MAX ? -1 : ans);
}