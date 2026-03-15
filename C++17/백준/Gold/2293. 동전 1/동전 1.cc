#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    vector<int> dp(k+1);
    
    dp[0] = 1;
    
    for(int i = 0; i < n; i++)
    {
        int cur = coins[i];
        for(int j = cur; j <= k; j++)
        {
            dp[j] += dp[j - cur];
        }
    }
    cout << dp[k];
}