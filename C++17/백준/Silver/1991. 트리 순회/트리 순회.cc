#include <bits/stdc++.h>
using namespace std;

int n;
int l[30], r[30];

void preorder(int cur)
{
    cout << char('A' + cur);
    if(l[cur] != 0) preorder(l[cur]);
    if(r[cur] != 0) preorder(r[cur]);
}

void inorder(int cur)
{
    if(l[cur] != 0) inorder(l[cur]);
    cout << char('A' + cur);
    if(r[cur] != 0) inorder(r[cur]);
}

void postorder(int cur)
{
    if(l[cur] != 0) postorder(l[cur]);
    if(r[cur] != 0) postorder(r[cur]);
    cout << char('A' + cur);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        char a, b, c;
        cin >> a >> b >> c;
        l[a-'A'] = b == '.' ? 0 : b - 'A';
        r[a-'A'] = c == '.' ? 0 : c - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}