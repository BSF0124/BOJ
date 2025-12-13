#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dir = 0;
    for(int i = 0; i < 10; i++)
    {
        int cmd;
        cin >> cmd;
        
        switch (cmd)
        {
            case 1:
                dir++;
                break;
            case 2:
                dir += 2;
                break;
            case 3:
                dir--;
        }

        dir = (dir % 4 + 4) % 4;
    }

    switch (dir)
    {
        case 0:
            cout << 'N';
            break;
        case 1:
            cout << 'E';
            break;
        case 2:
            cout << 'S';
            break;
        case 3:
            cout << 'W';
            break;
    }
}