#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<int> adj[10001];
bool visited[10001];
int connected[10001];

int count(int cur)
{
    fill(visited, visited+n+1, 0);
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;
    
    int cnt = 1;
    
    while(!q.empty())
    {
        int com = q.front();
        q.pop();
        
        for(const int& next : adj[com])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    int max_connected = 0;
    
    for (int i = 1; i <= n; i++) {
        connected[i] = count(i);
        if (connected[i] > max_connected) {
            max_connected = connected[i];
        }
    }
    
    for (int i = 1; i <= n; i++) 
    {
        if (connected[i] == max_connected) 
        {
            cout << i << ' ';
        }
    }
}