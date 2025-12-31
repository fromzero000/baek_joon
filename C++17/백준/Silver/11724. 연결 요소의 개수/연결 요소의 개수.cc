#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1001];
bool visited[1001];

void dfs(int cur) {
    visited[cur] = true;
    
    for(int nxt : adj[cur]){
        if(!visited[nxt]){
            dfs(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int answer = 0;
    
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            answer++;
            dfs(i);
        }
    }
    
    cout << answer;
    
    return 0;
}