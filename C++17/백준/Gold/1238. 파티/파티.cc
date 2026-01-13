#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, X;

vector<pair<int, int>> adj[1001];
vector<pair<int, int>> rev[1001];

vector<int> dijkstra(int start, vector<pair<int, int>> road[]){
    vector<int> result(N+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    result[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int current = pq.top().second;
        
        pq.pop();
        if(result[current] < cost) continue;
        for(pair<int, int> next : road[current]){
            int next_node = next.second;
            int next_cost = cost + next.first;
            
            if(next_cost < result[next_node]){
                result[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    return result;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> X;
    while(M--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        rev[v].push_back({w,u});
    }
    
    vector<int> to_X = dijkstra(X, rev);
    vector<int> from_X = dijkstra(X, adj);
    
    int longest = 0;
    for(int i = 1; i <= N; i++){
        if(to_X[i]+from_X[i] > longest) longest = to_X[i]+from_X[i];
    }
    cout << longest;
}