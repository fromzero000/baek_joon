#include <bits/stdc++.h>
using namespace std;

int a[1000000];
int n, b, c;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    cin >> b >> c;
    
    long result = 0;
    
    for(int i = 0; i < n; i++)
    {
        result++;
        a[i] -= b;
        
        if(a[i] > 0) 
        {
            result += a[i]/c;
            if(a[i]%c != 0) result++;
        }
    }
    
    cout << result;
}