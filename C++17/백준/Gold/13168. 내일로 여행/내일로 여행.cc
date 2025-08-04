#include <bits/stdc++.h>
using namespace std;

int n, r, cc = 0;
unordered_map<string, int> c;
vector<int> dir;
int d[2][102][102];

int trans_code(string &str)
{
    if((str[0] == 'S' || str[0] == 'V') && str[1] == '-') return 1;
    else if(str[0] == 'I' || str[0] == 'M') return 2;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    r *= 2;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if(c.find(str) == c.end())
            c[str] = cc++;
    }

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str; 
        cin >> str;
        dir.push_back(c[str]);
    }

    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < cc; i++)
    {
        d[0][i][i] = 0;
        d[1][i][i] = 0;
    }

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string type, st, en;
        int cost;
        cin >> type >> st >> en >> cost;
        cost *= 2;

        int u = c[st], v = c[en];

        cost = min(d[0][u][v], cost);
        d[0][u][v] = cost;
        d[0][v][u] = cost;

        int trcode = trans_code(type);
        if(trcode == 2) cost = 0;
        else if(trcode == 1) cost /= 2;

        cost = min(d[1][u][v], cost);
        d[1][u][v] = cost;
        d[1][v][u] = cost;
    }

    for(int k = 0; k < cc; k++)
        for(int i = 0; i < cc; i++)
            for(int j = 0; j < cc; j++)
                for(int m = 0; m < 2; m++)
                    d[m][i][j] = min(d[m][i][j], d[m][i][k] + d[m][k][j]);

    for(int i = 0; i < dir.size()-1; i++)
    {
        r -= d[0][dir[i]][dir[i+1]];
        r += d[1][dir[i]][dir[i+1]];
    }

    cout << (r < 0 ? "Yes" : "No");
}
