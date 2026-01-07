#include <bits/stdc++.h>
using namespace std;

bool graph[1001][1001];
int visited[1001][1001][2];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
bool broken = 1, unbroken = 0;
queue<pair<pair<int, int>, bool>> q;

int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M; int MAX = N*M;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            graph[i][j] = input[j]-'0';
        }
    }
    visited[0][0][unbroken] = 1;
    
    q.push({{0,0}, 0});
    while(!q.empty()){
        pair<pair<int, int>, bool> current = q.front();
        q.pop();
        int r = current.first.first;
        int c = current.first.second;
        bool w = current.second;
        if(r==N-1 && c==M-1) {
            cout << visited[r][c][w];
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr<0||nr>=N||nc<0||nc>=M) continue;
            if(visited[nr][nc][w]!=0) continue;
            if(!graph[nr][nc]){
                visited[nr][nc][w] = visited[r][c][w]+1;
                q.push({{nr, nc}, w});
                continue;
            }
            if(graph[nr][nc] && !w && visited[nr][nc][1]==0){
                visited[nr][nc][broken] = visited[r][c][w]+1;
                q.push({{nr, nc}, broken});
            }
        }
    }
    cout << -1;
}