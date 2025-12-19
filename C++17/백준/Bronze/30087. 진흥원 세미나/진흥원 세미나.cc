#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> seminar;
    seminar["Algorithm"] = "204";
    seminar["DataAnalysis"] = "207";
    seminar["ArtificialIntelligence"] = "302";
    seminar["CyberSecurity"] = "B101";
    seminar["Network"] = "303";
    seminar["Startup"] = "501";
    seminar["TestStrategy"] = "105";

    int n;
    string str;
    cin >> n;
    while(n--)
    {
        cin >> str;
        cout << seminar[str] << '\n';
    }
}