#include <bits/stdc++.h>
using namespace std;

int n, s, e, m;
bool dp[2001][2001];
int sequence[2001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> sequence[i];
    }
    
    
    for(int i = 1; i <= n; i++)
        dp[i][i] = 1;
    
    for(int i = 1; i <= n-1; i++)
        dp[i][i+1] = sequence[i]==sequence[i+1];
    
    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i <= n-len+1; i++)
        {
            int j = i+len-1;
            dp[i][j] = dp[i+1][j-1]&&(sequence[i]==sequence[j]);
        }
    }
    cin >> m;
    while(m--)
    {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}