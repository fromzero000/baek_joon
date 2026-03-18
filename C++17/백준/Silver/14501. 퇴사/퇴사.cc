#include <bits/stdc++.h>
using namespace std;


int n;
int t[17];
int p[17];
int dp[17];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];
    
    for(int i = 1; i <= n; i++)
    {
        dp[i+1] = max(dp[i], dp[i+1]);
        
        int next = i+t[i];
        if(next <= n+1)
        {
            dp[next] = max(dp[i]+p[i], dp[next]);
        }
    }
    cout << dp[n+1];
}