#include <bits/stdc++.h>
using namespace std;

int dp[21][10001]; //i번째 동전까지 썼을 때 j원을 만드는 방법 수 dp[i][j]
int coins[21];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, target;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < N; i++){
            cin >> coins[i];
        }
        cin >> target;
        for(int i = 0; i < N; i++){
            fill(dp[i]+1, dp[i]+target+1, 0);
        }
        for(int i = 0; i < N; i++){
            for(int j = 1; j <= target; j++){
              if(i>=1) dp[i][j] += dp[i-1][j];
                if(j>=coins[i]) dp[i][j] += dp[i][j-coins[i]];
            }
        }
        
        cout<<dp[N-1][target]<<'\n';
    }
}