#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char board[12][12];
unordered_map<string, int> cnt;

int dx[8]{1,0,-1,0,1,1,-1,-1};
int dy[8]{0,1,0,-1,1,-1,1,-1};

void dfs(int x, int y, int depth, string str)
{
    if(depth >= 1 & depth <= 5) cnt[str]++;
    
    if(depth == 5) return;

    for(int dir = 0; dir < 8; dir++)
    {
        int nx = (x + dx[dir] + n) % n;
        int ny = (y + dy[dir] + m) % m;
        dfs(nx, ny, depth+1, str+board[nx][ny]);
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
            
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dfs(i, j, 1, string (1, board[i][j]));
    
    for(int i = 0; i < k; i++)
    {
        string str;
        cin >> str;
        cout << cnt[str] << '\n';
    }
}