#include <bits/stdc++.h>
using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int dist[300001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k >> x;
    fill(dist, dist+n+1, -1);
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    deque<int> deq;
    deq.push_front(x);
    dist[x] = 0;
    while(!deq.empty()){
        int current = deq.front();
        deq.pop_front();

        for(const int& neighbor : graph[current]){
            if(dist[neighbor] == -1){
                dist[neighbor] = dist[current]+1;
                deq.push_back(neighbor);
            }
        }
    }
    bool isK = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i]==k){
            isK = 1;
            cout<<i<<'\n';
        }
    }
    if(!isK) cout << -1;
}