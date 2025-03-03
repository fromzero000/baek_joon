#include <bits/stdc++.h>
using namespace std;

int n, k;
int w[105];
int v[105];
//6 13
//4 8
//3 6
//5 12
int dp[105][1000005];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>w[i]>>v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i]>=0){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][k];
}