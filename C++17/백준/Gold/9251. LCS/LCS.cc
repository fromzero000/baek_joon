#include <bits/stdc++.h>
using namespace std;

string str1;
string str2;

int dp[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str1 >> str2;
    
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    
    cout << dp[str1.size()][str2.size()];
}