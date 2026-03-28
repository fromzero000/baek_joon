#include <bits/stdc++.h>
using namespace std;

int dp[4001][4001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    
    cin >> a >> b;
    int longest = 0;
    for(int i = 0; i < a.length(); i++)
        if(a[0] == b[i]) dp[0][i] = 1;
    for(int i = 0; i < b.length(); i++)
        if(b[0] == a[i]) dp[i][0] = 1;
    for(int i = 1; i < a.length(); i++)
    {
        for(int j = 1; j < b.length(); j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                longest = max(dp[i][j], longest);
            }
        }
    }
        
    cout << longest;
    return 0;
}