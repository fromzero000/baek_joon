#include <bits/stdc++.h>
using namespace std;
int _x[6] = {0,1,0,-1,0,0};
int _y[6] = {1,0,-1,0,0,0};
int _z[6] = {0,0,0,0,1,-1};
int q[1000005][3];
int box[100][100][100];
int days[100][100][100];
int head =0, tail = 0;
void push(int z,int x,int y){
    q[tail][0] = z;q[tail][1] = x;q[tail++][2] = y;
}
void pop(){
    head++;
}
int* front(){
    return q[head];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m,n,h;
    cin>>m>>n>>h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                cin>>box[i][j][k];
                if(box[i][j][k] == 0) days[i][j][k] = -1;
                if(box[i][j][k] == 1) push(i,j,k);
            }
        }
    }
    while(head!=tail){
        int current[3] = {front()[0],front()[1],front()[2]};pop();
        for(int d = 0; d < 6; d++){
            int z = current[0] + _z[d];
            int x = current[1] + _x[d];
            int y = current[2] + _y[d];
            if(x < 0 || y < 0 || z < 0 || x >= n || y >= m || z >= h) continue;
            if(days[z][x][y] >= 0) continue;
            days[z][x][y] = days[current[0]][current[1]][current[2]] + 1;
            push(z,x,y);
        }
    }
    int answer = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(days[i][j][k]==-1){
                    cout<<-1;
                    return 0;
                }
                answer = max(answer, days[i][j][k]);
            }
        }
    }
    cout<<answer;
}