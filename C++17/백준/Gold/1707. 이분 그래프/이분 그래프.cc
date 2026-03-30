#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> nodes(v+1, vector<int>());
    vector<int> colors(v+1);
    queue<int> q;
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    bool isBipartite = true;
    for(int i = 1; i <= v; i++)
    {
        if(!isBipartite) break;
        if(colors[i] == 0)
        {
            colors[i] = 1;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                int color = colors[cur];
                for(int next : nodes[cur])
                {
                    if(colors[next] == color)
                    {
                        isBipartite = false;
                        break;
                    }
                    if(colors[next] == 0)
                    {
                        colors[next] = -color;
                        q.push(next);
                    }
                }
            }
            if(!isBipartite) break;
        }
    }
    cout << (isBipartite?"YES":"NO") << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        solve();
    }
}