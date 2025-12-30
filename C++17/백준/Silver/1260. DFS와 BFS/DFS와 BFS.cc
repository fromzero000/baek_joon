#include <bits/stdc++.h>
using namespace std;


bool graph[1001][1001];
bool visited[1001];
stack<int> depth;
queue<int> breadth;
int N, M, V;

void DFS(int start){
    depth.push(start);
    while(!depth.empty()){
        int current = depth.top();
        depth.pop();
        if(visited[current]) continue;
        cout << current<< ' ';
        visited[current] = 1;
        for(int i = 1; i <= N; i++){
            if(graph[current][i] && !visited[i]) DFS(i);
        }
    }
}

void BFS(int start){
    breadth.push(start);
    while(!breadth.empty()){
        int current = breadth.front();
        breadth.pop();
        if(visited[current]) continue;
        cout << current<< ' ';
        visited[current] = 1;
        for(int i = 1; i <= N; i++){
            if(graph[current][i] && !visited[i]) breadth.push(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> V;
    int s, e;
    while(M--){
        cin >> s >> e;
        graph[s][e] = 1;
        graph[e][s] = 1;
    }
    DFS(V);
    fill(visited, visited+1001, 0);
    cout<<'\n';
    BFS(V);
}