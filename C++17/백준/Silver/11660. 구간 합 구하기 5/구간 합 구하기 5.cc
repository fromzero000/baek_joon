#include <bits/stdc++.h>
using namespace std;

int N, M;

int matrix[1025][1025];
long long sums[1025][1025];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            cin >> matrix[i][j];
            sums[i][j] += matrix[i][j];
            sums[i][j] += sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
        }
    }

    int x1, x2, y1, y2;
    while(M--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<sums[y2][x2] - sums[y1-1][x2] - sums[y2][x1-1] + sums[y1-1][x1-1]<<'\n';
    }
}