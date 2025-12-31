#include <bits/stdc++.h>
using namespace std;

int row, col;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int Map[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> row >> col;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cin >> Map[i][j];
      if(Map[i][j]==2) {
        dist[i][j] = 0;
        q.push({i, j});
      }
      else if(Map[i][j]==1) {
        dist[i][j] = 1000005;
      }
      else{
        dist[i][j] = 0;
      }
    }
  }
  //2 0 0 1
  //1 0 1 1
  //1 0 1 1
  //1 1 1
  while(!q.empty()){
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for(int i = 0; i < 4; i++){
      int y = r+dy[i]; int x = c+dx[i];
      if(y<0||y>=row||x<0||x>=col) continue;
      if(Map[y][x]==0 || Map[y][x]==2) continue;
      if(dist[y][x]==0) continue;
      if(visited[y][x]) continue;
      visited[y][x] = 1;
      dist[y][x] = min(dist[y][x], dist[r][c]+1);
      q.push({y,x});
    }    
  }
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(dist[i][j]==1000005) cout<<-1<<' ';
      else cout<<dist[i][j]<<' ';
    }
    cout<<'\n';
  }
}
