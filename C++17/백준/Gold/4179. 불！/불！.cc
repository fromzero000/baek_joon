#include <bits/stdc++.h>
using namespace std;

string maze[1002];
int Jdistances[1002][1002];
int Fdistances[1002][1002];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    cin>>r>>c;
    queue<pair<int,int>> F;
    queue<pair<int,int>> J;
    for(int i = 0; i < r; i++){
        fill(Jdistances[i],Jdistances[i]+c,-1);
        fill(Fdistances[i],Fdistances[i]+c,-1);
    }
    for(int i = 0; i < r; i++){
        cin>>maze[i];
        for(int j = 0; j < c; j++){
            if(maze[i][j]=='F'){
                Fdistances[i][j] = 0;
                F.push({i,j});
            }
            if(maze[i][j]=='J'){
                Jdistances[i][j] = 0;
                J.push({i,j});
            }
        }
    }
    while(!F.empty()){
        auto current = F.front();F.pop();
        for(int d = 0; d < 4; d++){
            int x = current.first + dx[d];
            int y = current.second + dy[d];
            if(x<0||y<0||x>r-1||y>c-1) continue;
            if(maze[x][y]=='#'||Fdistances[x][y]>-1) continue;
            Fdistances[x][y] = Fdistances[current.first][current.second] + 1;
            F.push({x,y});
        }
    }
    
    while(!J.empty()){
        auto current = J.front();J.pop();
        for(int d = 0; d < 4; d++){
            int x = current.first + dx[d];
            int y = current.second + dy[d];  
            if(x<0||y<0||x>r-1||y>c-1){
                cout<<Jdistances[current.first][current.second] + 1;
                return 0;
            }          
            if(maze[x][y]=='#'||Jdistances[x][y]>-1) continue;
            if(Fdistances[x][y]!=-1&&Jdistances[current.first][current.second]+1>=Fdistances[x][y]) continue;
            Jdistances[x][y] = Jdistances[current.first][current.second] + 1;
            J.push({x,y});
        }
    }
    cout<<"IMPOSSIBLE";
}