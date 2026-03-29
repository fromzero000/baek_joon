#include <bits/stdc++.h>
using namespace std;

void solve() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V + 1);
    vector<int> color(V + 1, 0);

    for (int i = 0; i < E; ++i) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBipartite = true;

    for (int i = 1; i <= V; ++i) 
    {
        if (!isBipartite) break;
        if (color[i] == 0) 
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) 
            {
                int curr = q.front();
                q.pop();

                for (int next : adj[curr]) 
                {
                    if (color[next] == 0) 
                    {
                        color[next] = 3 - color[curr];
                        q.push(next);
                    } 
                    else if (color[next] == color[curr]) 
                    {
                        isBipartite = false;
                        break;
                    }
                }
                if (!isBipartite) break;
            }
        }
    }
    if (isBipartite) 
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> K;
    while (K--) 
        solve();

    return 0;
}