#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n--)
    {
        bool chk = 1;
        string a, b;
        cin >> a >> b;

        int used[26] = {};

        for(char ch : a)
            used[ch-'a']++;

        for(char ch : b)
            used[ch-'a']--;

        for(auto i : used)
        {
            if(i != 0)
            {
                chk = 0;
                break;
            }
        }
        
        cout << a << " & " << b << " are ";
        if(!chk) cout << "NOT ";
        cout << "anagrams.\n";
    }
}