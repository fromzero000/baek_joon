#include <bits/stdc++.h>
using namespace std;


struct State
{
    int cur_id;
    vector<int> visited;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> adj(n+1);
    
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for_each(adj.begin(), adj.end(), [](vector<int>& neighbors)
             {
                 sort(neighbors.begin(), neighbors.end());
             }
    );
    
    
    State init = {1, vector<int>(n+1, 0)};
    int id = 1;
    auto dfs = [&](auto& self, State& state, int cur_node)->State&
    {
        state.visited[cur_node] = state.cur_id++;
        return accumulate(
        adj[cur_node].begin(),
        adj[cur_node].end(),
        ref(state),
        [&](reference_wrapper<State> st_ref, int next_node)->reference_wrapper<State>
            {
                State& cur = st_ref.get();
                
                if(cur.visited[next_node] == 0)
                {
                    return self(self, cur, next_node);
                }
                return cur;
            }).get();
    };
    
    auto result = dfs(dfs, init, r);
    
    for(int i = 1; i <= n; i++)
        cout << result.visited[i] << '\n';
}