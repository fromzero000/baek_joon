#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, k;
    cin >> t;
    
    while(t--)
    {
        cin >> n >> k;
        int times[n+1]; //단일 건축 시간
        for(int i = 1; i <= n; i++)
        {
            cin >> times[i];
        }
        vector<int> next[n+1]; // 선행 건물 조건
        vector<int> deg(n+1, 0);
        vector<int> dp(n+1, 0);
        
        int x, y, w;
        for(int i = 0; i < k; i++)
        {
            cin >> x >> y;
            next[x].push_back(y);
            deg[y]++;
        }
        cin >> w;
        queue<int> q;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = times[i];
            if(deg[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int current = q.front();q.pop();
            for(int i : next[current])
            {
                dp[i] = max(dp[i], dp[current]+times[i]);
                deg[i]--;
                if(deg[i]==0) q.push(i);
            }
        }
        cout << dp[w] << '\n';
    }
    
}