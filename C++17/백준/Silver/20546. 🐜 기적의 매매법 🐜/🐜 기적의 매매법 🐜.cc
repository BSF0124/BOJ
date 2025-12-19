#include <bits/stdc++.h> 
using namespace std;

struct p
{
    int money;
    int cnt = 0;
};

int n, price[14];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    p JH, SM;
    JH.money = n;
    SM.money = n;

    for(int i = 0; i < 14; i++)
        cin >> price[i];

    int up = 0, down = 0, tmp = price[0];
    for(int i = 0; i < 14; i++)
    {
        JH.cnt += JH.money / price[i];
        JH.money %= price[i];

        if(i > 0)
        {
            if(price[i] > price[i-1])
            {
                down = 0;
                if(++up >= 3)
                {
                    SM.money += SM.cnt * price[i];
                    SM.cnt = 0;
                }
            }
            else if(price[i] < price[i-1])
            {
                up = 0;
                if(++down >= 3)
                {
                    SM.cnt += SM.money / price[i];
                    SM.money %= price[i];
                }
            }
        }
    }

    JH.money += JH.cnt * price[13];
    SM.money += SM.cnt * price[13];

    if(JH.money > SM.money) cout << "BNP";
    else if(JH.money < SM.money) cout << "TIMING";
    else cout << "SAMESAME";
}