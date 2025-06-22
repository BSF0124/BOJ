#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0;
    string str;
    cin >> n;

    while(n)
    {
        cin >> str;

        if(str.front() - 'A' >= 0 && str.front() - 'A' <= 25)
        {
            bool chk = 1;
            int en = str.length();
            if(str.back() == '.' || str.back() == '?' || str.back() == '!') en--;

            for(int i = 1; i < en; i++)
            {
                if(str[i] - 'a' < 0 || str[i] - 'a' > 25)
                {
                    chk = 0;
                    break;
                }
            }
            cnt += chk;
        }

        if(str.back() == '.' || str.back() == '?' || str.back() == '!')
        {
            cout << cnt << '\n';
            cnt = 0;
            n--;
        }
    }
}