#include <bits/stdc++.h>
using namespace std;

int users[101][101];
int points[101];
const int INF = 101;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, s, e;
    cin >> N >> M;
    for(int i = 0; i < 101; i++)
        fill(users[i], users[i]+101,INF);
    
    while(M--){
        cin >> s >> e;
        users[s][e] = 1;
        users[e][s] = 1;
    }
    for(int i = 1; i <= N; i++) users[i][i] = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                users[j][k] = users[k][j] = min(users[j][k], users[j][i]+users[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            points[i] += users[i][j];
        }
    }
    cout<<min_element(points+1, points+N+1)-points;
}