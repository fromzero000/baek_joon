#include <bits/stdc++.h>
using namespace std;


int dp[501][501];
vector<pair<int, int>> matrices;
int solve(int st, int en)
{
    if(st==en) return 0;
    
    if(dp[st][en] != -1)
        return dp[st][en];
    int min_cost = 0x7fffffff;
    
    for(int k = st; k < en; k++)
    {
        int cur = solve(st, k) + solve(k+1, en)
            + matrices[st].first*matrices[k].second*matrices[en].second;
        
        min_cost = min(cur, min_cost);
    }
    dp[st][en] = min_cost;
    return dp[st][en];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    
    cin >> n;
    for(int i = 0; i < n; i++)
        fill(dp[i], dp[i]+n, -1);
    
    for(int i = 0; i < n; i++)
    {
        cin >> r >> c;
        matrices.push_back({r, c});
    }
    int result = solve(0, n-1);
    cout << result;
}