#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    a *= b;
    a *= c;

    int arr[10] = {0};

    while(a > 0)
    {
        arr[a%10]++;
        a /= 10;
    }


    for(int i = 0 ; i < 10; i++)
        cout << arr[i] << '\n';
}