#include <bits/stdc++.h>
using namespace std;

string str;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1)
    {
        cin >> str;

        if(str == "#")
            return 0;

        bool chk = 1;
        if(str.size() > 1)
        {
            for(int i = 0; i < str.size()-1; i++)
            {
                int diff = str[i+1] - str[i];
                if(diff < 0) diff += 7;
                
                if(!(diff == 2 || diff == 4 || diff == 6))
                {
                    chk = 0;
                    break;
                }
            }
        }

        cout << (chk ? "That music is beautiful." : "Ouch! That hurts my ears. ") << '\n';
    }
}