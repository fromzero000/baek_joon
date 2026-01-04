#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> tree[100001];
int p[100001];
queue<int> q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    int u, v;
    for(int i = 0; i < N; i++){      
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int root = 1;
    q.push(root);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(const int &c : tree[current]){
            if(p[current] == c) continue;
            p[c] = current;
            q.push(c);
        }
    }
    for(int i = 2; i <= N; i++) cout<<p[i]<<'\n';
}