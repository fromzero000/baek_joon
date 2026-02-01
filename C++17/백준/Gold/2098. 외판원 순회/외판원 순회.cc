#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
int n;
int dist[16][16];
int dp[16][1<<16];
int tsp(int cur, int visited)
{
    if(visited == (1 << n)-1)
    {
        if(dist[cur][0] > 0) return dist[cur][0];
        return INF;
    }
    
    if(dp[cur][visited] != -1)
        return dp[cur][visited];
    
    dp[cur][visited] = INF;
    
    for(int next = 0; next < n; next++)
    {
        if((visited & (1 << next)) == 0 && dist[cur][next] > 0)
        {
            int t = tsp(next, visited | (1 << next));
            if(t != INF)
                dp[cur][visited] = min(dp[cur][visited], t + dist[cur][next]);
        }
    }
    return dp[cur][visited];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1);
}