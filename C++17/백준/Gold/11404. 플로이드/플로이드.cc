#include <bits/stdc++.h>
using namespace std;


int n, m;
int cost[101][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    int cost_max = 100*100000+1;
    int s, d, c;
    for(int i = 1; i <= n; i++){
        fill(cost[i]+1, cost[i]+n+1, cost_max);
    }
    while(m--){
        cin >> s >> d >> c;
        cost[s][d] = min(c, cost[s][d]);
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j==k) continue;
                cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int  j = 1; j <= n; j++){
            if(cost[i][j] == cost_max) cout << 0 <<' ';
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}