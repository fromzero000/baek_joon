#include <bits/stdc++.h>
using namespace std;

int triangle[500][500];
int dp[500][500];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        int _max = 0;
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
            if(i == N-1){
                dp[i][j] = triangle[i][j];
            }
        }
    }
    
    for(int i = N-2; i >= 0; i--){
        for(int j = N-1; j >= 0; j--){
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
    }
    cout << dp[0][0];
}