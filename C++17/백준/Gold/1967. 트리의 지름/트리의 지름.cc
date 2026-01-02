#include <bits/stdc++.h>
using namespace std;

int weights[10001];
int n;
int diameter = 0;
vector<int> nodes[10001];

int dfs(int current){
    int max1 = 0;
    int max2 = 0;
    
    for(const int& child : nodes[current]){
        int next = child;
        int w = weights[child];
        
        int current_depth = dfs(next) + w;
        
        if(current_depth > max1) {
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
    
    cin >> n;
    int p, c, w;
    for(int i = 0; i < n-1; i++){
        cin >> p >> c >> w;
        weights[c] = w;
        nodes[p].push_back(c);
    }
    
    dfs(1);
    
    cout<<diameter;
}