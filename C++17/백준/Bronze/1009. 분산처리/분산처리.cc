#include <bits/stdc++.h>
using namespace std;


int a, b, t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        a %= 10;
        int a1 = 1;
        while(b--)
        {
            a1 *= a;
            a1 %= 10;
        }
        if(a1 == 0) cout << 10 << '\n';
        else cout << a1 << '\n';
    }
}