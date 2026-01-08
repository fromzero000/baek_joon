#include <bits/stdc++.h>
using namespace std;

//트리 지름 => dfs
vector<pair<int, int>> tree[100001];
int V;
int diameter{};
int dfs(int current, int parent){
    int max1{}, max2{};
    
    for(const pair<int, int>& next_node : tree[current]){
        int next = next_node.first;
        int len = next_node.second;
        if(next==parent) continue;
        int current_depth = dfs(next, current)+len;
        if(current_depth > max1){
            max2 = max1;
            max1 = current_depth;
        }
        else if(current_depth > max2){
            max2 = current_depth;
        }
    }
    diameter = max(diameter, max1+max2);
    return max1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V;
    int u{},v{},l{};
    for(int i = 0; i < V; i++){
        cin >> u;
        while(1){
            cin >> v;
            if(v==-1) break;
            cin >> l;
            tree[u].push_back({v,l});
        }
    }
    dfs(1,0);
    cout << diameter;
}