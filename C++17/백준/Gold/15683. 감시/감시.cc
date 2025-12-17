#include <bits/stdc++.h> 
using namespace std;

int n,m, ans = 64;
int board[10][10];
vector<tuple<int,int,int>> cctvs;

vector<vector<vector<int>>> dir = {
    {},
    {{0},{1},{2},{3}},                  // 1
    {{0,2},{1,3}},                      // 2
    {{0,1},{1,2},{2,3},{3,0}},          // 3
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},  // 4
    {{0,1,2,3}}                         // 5
};

void Count_Board()
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += (board[i][j] == 0);

    ans = min(ans, cnt);
}

void Fill_Up(int x, int y)
{
    for(int i = x-1; i >= 0; i--)
    {
        if(board[i][y] == 6) return;
        if(board[i][y] == 0) board[i][y] = 9;
    }
}

void Fill_Down(int x, int y)
{
    for(int i = x+1; i < n; i++)
    {
        if(board[i][y] == 6) return;
        if(board[i][y] == 0) board[i][y] = 9;
    }
}

void Fill_Left(int x, int y)
{
    for(int i = y-1; i >= 0; i--)
    {
        if(board[x][i] == 6) return;
        if(board[x][i] == 0) board[x][i] = 9;
    }
}

void Fill_Right(int x, int y)
{
    for(int i = y+1; i < m; i++)
    {
        if(board[x][i] == 6) return;
        if(board[x][i] == 0) board[x][i] = 9;
    }
}

void Watch(int x, int y, int d)
{
    if(d == 0) Fill_Right(x,y);
    else if(d == 1) Fill_Down(x,y);
    else if(d == 2) Fill_Left(x,y);
    else if(d == 3) Fill_Up(x,y);
}

void func(int cnt)
{
    if(cnt == cctvs.size())
    {
        Count_Board();
        return;
    }

    auto [x, y, type] = cctvs[cnt];
    int _board[10][10];

    for(auto &dirs : dir[type])
    {
        memcpy(_board, board, sizeof(board));

        for(auto d : dirs)
            Watch(x, y, d);
        
        func(cnt+1);

        memcpy(board, _board, sizeof(board));
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5)
                cctvs.push_back({i,j,board[i][j]});
        }
    }
    func(0);
    cout << ans;
}