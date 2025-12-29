#include <bits/stdc++.h>
using namespace std;

int apt[15][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, k, n;
    cin >> T;
    iota(*apt+1, *apt+15,1);

    while(T--){
        cin >> k >> n;
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                apt[i][j] = accumulate(apt[i-1]+1, apt[i-1]+j+1,0);
            }
        }
        cout<<apt[k][n]<<'\n';
    }
}