#include <bits/stdc++.h> 
using namespace std;

int n, k;
string lyrics[15] = 
{
    "",
    "baby",
    "sukhwan",
    "tururu",
    "turu",
    "very",
    "cute",
    "tururu",
    "turu",
    "in",
    "bed",
    "tururu",
    "turu",
    "baby",
    "sukhwan"
};

void print_Turu()
{
    if(k >= 5)
        cout << "tu+ru*" << k;
    else
    {
        cout << "tu";
        for(int i = 0; i < k; i++)
            cout << "ru";
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    k = (n-1) / 14;
    n = (n-1) % 14 + 1;

    if(n == 3 || n == 7 || n == 11)
    {
        k += 2;
        print_Turu();
    }
    
    else if(n == 4 || n == 8 || n == 12)
    {
        k++;
        print_Turu();
    }

    else
        cout << lyrics[n];
}