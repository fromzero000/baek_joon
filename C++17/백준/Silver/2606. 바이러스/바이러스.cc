#include <bits/stdc++.h>
using namespace std;

bool connected[101][101];
bool infected[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, s, e, answer = 0;
    cin >> N >> M;
    infected[1] = 1;
    if(M==0){
        cout<<answer;
        return 0;
    }
    while(M--){
        cin >> s >> e;
        connected[s][e] = connected[e][s] = 1;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                connected[j][k] = connected[k][j] = connected[j][k] || (connected[j][i]&&connected[i][k]);
            }
        }
    }
    for(int i = 2; i <= N; i++){
      if(connected[i][1]) answer += 1;
    }
    cout<<answer;
}