#include <bits/stdc++.h>
using namespace std;

vector<int> friends[2000];

bool solve(int cur, int depth, bitset<2000> visited)
{
    if(depth == 5)
        return true;
    
    visited.set(cur);
    return any_of(friends[cur].begin(), friends[cur].end(), [&](int next)
                  {
                      if(!visited[next])
                      {
                          return solve(next, depth+1, visited);
                      }
                      return false;
                  });
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 0);
    
    bool result = any_of(nodes.begin(),nodes.end(), [](int start_node){return solve(start_node, 1, bitset<2000>());});
        
    if(result)
        cout << 1;
    else cout << 0;
}