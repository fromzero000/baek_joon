#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<int> friends[2000];
bool visited[2000];

bool solve(int cur, int depth)
{
    if(depth >= 5)
        return true;
    
    for(const int& next : friends[cur])
    {
        if(visited[next]) continue;
        visited[next] = true;
        if(solve(next, depth+1))
        {
            return true;
        }
        visited[next] = false;
    }
    visited[cur] = false;  
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++)
    {
        fill(visited, visited+n, false);
        visited[i] = 1;
        if(solve(i, 1))
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}