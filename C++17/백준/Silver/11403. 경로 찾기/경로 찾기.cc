#include <bits/stdc++.h>
using namespace std;

bool G[100][100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> G[i][j];
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(G[j][i]&&G[i][k]) G[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << G[i][j] << ' ';
        cout<<'\n';
    }
}