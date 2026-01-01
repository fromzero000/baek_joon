#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int stickers[2][100000];
int dp[2][100000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> T;
    while(T--){
        cin >> n;
        fill(stickers[0], stickers[0]+n,0);
        fill(stickers[1], stickers[1]+n,0);
        fill(dp[0], dp[0]+n,0);
        fill(dp[1], dp[1]+n,0);
      
        for (int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                cin >> stickers[i][j];
            }
        }

      dp[0][0] = stickers[0][0];
      dp[1][0] = stickers[1][0];

      for(int i = 1; i < n; i++){
          dp[0][i] = stickers[0][i]+max(dp[1][i-1], dp[1][i-2]);
          dp[1][i] = stickers[1][i]+max(dp[0][i-1], dp[0][i-2]);
      }

      cout << max(dp[0][n-1], dp[1][n-1])<<'\n';
    }
    
    
}