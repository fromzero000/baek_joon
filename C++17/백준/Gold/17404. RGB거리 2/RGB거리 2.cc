#include <bits/stdc++.h>
using namespace std;


int n;
int cost[1000][3];
int dp[1000][3];
int result = 1e9;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> cost[i][j];
            dp[i][j] = 1e9;
        }
    }
    
    for(int fclr = 0; fclr < 3; fclr++){
        for(int i = 0; i < 3; i++){
            if(fclr == i)
                dp[0][i] = cost[0][i];
            else
                dp[0][i] = 1e9;
        }
        
        for(int i = 1; i < n; i++){
            dp[i][0] = cost[i][0]+min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = cost[i][1]+min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = cost[i][2]+min(dp[i-1][1], dp[i-1][0]);
        }
        
        for(int lclr = 0; lclr < 3; lclr++){
            if(lclr == fclr)
                continue;
            result = min(result, dp[n-1][lclr]);
        }
    }
    cout << result;
}