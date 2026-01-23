#include <bits/stdc++.h>
using namespace std;


#define pii pair<int, int>

int v, e;
vector<pair<int, int>> adj[10005];
bool chk[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    long long ans = 0;
    int cnt = 0;

    pq.push({0, 1});
    
    while(cnt < v)
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        
        int cost = cur.first;
        int node = cur.second;
        
        if(chk[node]) continue;

        chk[node] = true;
        ans += cost;
        cnt++;
        
        for(const pair<int, int>& nxt : adj[node])
        {
            if(!chk[nxt.second]) 
                pq.push(nxt);
        }
    }
    
    cout << ans;
    
    return 0;
}