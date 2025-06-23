#include <bits/stdc++.h>
using namespace std;

struct Member
{
    string name;
    int apc;
};

int n;
vector<Member> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--)
    {
        string name, school, icpc;
        int s, a;
        cin >> name >> school >> icpc >> s >> a;

        if(school == "jaehak" && icpc == "notyet" && (s == -1 || s > 3))
            v.push_back({name, a});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.apc < b.apc;
    });
    
    if(v.size() > 10) 
        v.resize(10);
    
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.name < b.name;
    });

    cout << v.size() << '\n';
    for(auto &m : v)
        cout << m.name << '\n';
}