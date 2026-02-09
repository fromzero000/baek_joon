#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> adj[1000001];
int dp[1000001][2];
bool visited[1000001];

void dfs(int cur)
{
    visited[cur] = 1;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for(const int& next : adj[cur])
    {
        if(!visited[next])
        {
            dfs(next);
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    
    cout << min(dp[1][0], dp[1][1]);
}