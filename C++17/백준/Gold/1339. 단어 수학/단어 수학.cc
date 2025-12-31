#include <bits/stdc++.h> 
using namespace std;

int n, cur = 9;
long long ans = 0;
vector<string> words;
long long w[26] = {};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string str;
    while(n--)
    {
        cin >> str;
        words.push_back(str);
    }

    for(const string& word : words)
    {
        long long tmp = 1;
        for(int i = word.size()-1; i >= 0; i--)
        {
            w[word[i] - 'A'] += tmp;
            tmp *= 10;
        }
    }

    vector<long long> v;
    for(int i = 0; i < 26; i++)
        if(w[i] > 0) 
            v.push_back(w[i]);

    sort(v.begin(), v.end(), greater<long long>());

    for(long long l : v)
    {
        ans += l * cur;
        cur--;
    }

    cout << ans;
}