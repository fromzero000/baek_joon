#include <bits/stdc++.h>
using namespace std;

int N, M;
int degree[32001];
vector<int> order[32001];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int f, b;
        cin >> f >> b;
        degree[b]++;
        order[f].push_back(b);
    }
    
    for(int i = 1; i <= N; i++){
        if(degree[i]==0) q.push(i);
    }
    
    while(!q.empty()){
        int current = q.front();
        cout<<current<<' ';
        q.pop();
        for(int b : order[current]){
            degree[b]--;
            if(degree[b]==0){
                q.push(b);
            }
        }
    }
}