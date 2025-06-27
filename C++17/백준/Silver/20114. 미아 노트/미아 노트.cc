#include <bits/stdc++.h>
using namespace std;

int n, h ,w;
char word[102];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> w;

    fill(word, word+n, '?');

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < n*w; j++)
        {
            char ch;
            cin >> ch;
            if(ch != '?')
            {
                word[j/w] = ch;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << word[i];
}