/* https://youtu.be/ZmLe4tc5XRI?si=_MinK2Aqa1plIH0C
트라이 = 문자열을 효율적으로 처리하기 위한 트리 자료구조
- 단어 S를 삽입/탐색/삭제할 때 O(|S|)
- 문자열을 그냥 배열에 저장하는 것 보다 최대 '4*글자의 종류'배 만큼 더 사용
이론적인 시간복잡도와는 별개로 실제로는 트라이가 해시, 이진 검색 트리에 비해 훨씬 느림.
일반적인 상황에서는 해시나 이진 검색 트리를 사용하는게 좋으나
트라이의 성질을 사용해야 하는 문제가 여럿 존재
*/

#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
int nxt[MX][26];

int c2i(char c)
{
    return c - 'A';
}

void insert(string& s)
{
    int cur = ROOT;
    for(auto c : s)
    {
        if(nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
    chk[cur] = 1;
}

bool find(string& s)
{
    int cur = ROOT;
    for(auto c : s)
    {
        if(nxt[cur][c2i(c)] == -1) return 0;
        cur = nxt[cur][c2i(c)];
    }
    return chk[cur];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i]+26, -1);

    int n, m;
    cin >> n >> m;

    while(n--)
    {
        string s;
        cin >> s;
        insert(s);
    }

    int ans = 0;
    while(m--)
    {
        string s;
        cin >> s;
        ans += find(s);
    }
    cout << ans;
}