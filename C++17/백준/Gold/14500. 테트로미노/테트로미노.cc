#include <bits/stdc++.h> 
using namespace std;
#define X first
#define Y second

int n, m, ans = 0;
int board[500][500];

vector<vector<pair<int,int>>> tetromino = 
{
    {{0,0},{0,1},{0,2},{0,3}},
    {{0,0},{1,0},{2,0},{3,0}},
    {{0,0},{1,0},{0,1},{1,1}},
    {{0,0},{1,0},{2,0},{2,1}},
    {{0,0},{0,1},{0,2},{1,0}},
    {{0,0},{0,1},{1,1},{2,1}},
    {{0,2},{1,0},{1,1},{1,2}},
    {{0,1},{1,1},{2,0},{2,1}},
    {{0,0},{0,1},{0,2},{1,2}},
    {{0,0},{0,1},{1,0},{2,0}},
    {{0,0},{1,0},{1,1},{1,2}},
    {{0,0},{1,0},{1,1},{2,1}},
    {{0,1},{0,2},{1,0},{1,1}},
    {{0,1},{1,0},{1,1},{2,0}},
    {{0,0},{0,1},{1,1},{1,2}},
    {{0,0},{0,1},{0,2},{1,1}},
    {{0,0},{1,0},{1,1},{2,0}},
    {{0,1},{1,0},{1,1},{1,2}},
    {{0,1},{1,0},{1,1},{2,1}}
};

int func(int x, int y)
{
    int mx = 0;
    for(auto tet : tetromino)
    {
        int sum = 0;
        bool chk = 1;
        for(auto dir : tet)
        {
            int nx = x + dir.X;
            int ny = y + dir.Y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                chk = 0;
                break;
            }

            sum += board[nx][ny];
        }

        if(chk)
        {
            mx = max(mx, sum);
        }
    }

    return mx;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans = max(ans, func(i,j));
        }
    }

    cout << ans;
}