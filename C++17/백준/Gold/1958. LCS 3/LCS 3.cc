#include <bits/stdc++.h>
using namespace std;
vector<string> s(3);
int dp[101][101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 3; i++)
        cin >> s[i];
    
    int len0 = s[0].length();
    int len1 = s[1].length();
    int len2 = s[2].length();
    
    for(int i = 1; i <= len0; i++)
    {
        for(int j = 1; j <= len1; j++)
        {
            for(int k = 1; k <= len2; k++)
            {
                if(s[0][i-1] == s[1][j-1] && s[1][j-1] == s[2][k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                
                else
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
            }
        }
    }
    
    cout << dp[len0][len1][len2];
}