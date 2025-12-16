#include <bits/stdc++.h> 
using namespace std;

int board[9][9];
bool isused1[9][10];
bool isused2[9][10];
bool isused3[9][10];
vector<pair<int,int>> v;

int boxNum(int r, int c)
{
    return (r / 3) * 3 + (c / 3);
}

bool func(int idx)
{
    if(idx == v.size()) return 1;

    int r = v[idx].first;
    int c = v[idx].second;
    int b = boxNum(r,c);

    for(int i = 1; i <= 9; i++)
    {
        if(isused1[r][i] || isused2[c][i] || isused3[b][i]) continue;

        board[r][c] = i;
        isused1[r][i] = 1;
        isused2[c][i] = 1;
        isused3[b][i] = 1;

        if(func(idx+1)) return 1;

        board[r][c] = 0;
        isused1[r][i] = 0;
        isused2[c][i] = 0;
        isused3[b][i] = 0;
    }

    return 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int num;
            cin >> num;
            board[i][j] = num;

            if(num == 0) 
                v.push_back({i,j});
            else
            {
                isused1[i][num] = 1;
                isused2[j][num] = 1;
                isused3[boxNum(i,j)][num] = 1;
            }
        }
    }

    func(0);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}