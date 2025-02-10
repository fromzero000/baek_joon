#include <bits/stdc++.h>
using namespace std;
int box[1002][1002];
pair<int, int> q[1000005];
int days[1002][1002];
int head = 0, tail = 0;
int _x[4] = {0,1,0,-1};
int _y[4] = {1,0,-1,0};
void push(pair<int, int> p){
    q[tail++] = p;
}
void pop(){
    head++;
}
pair<int, int> front(){
    return q[head];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N;
    cin>>M>>N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>box[i][j];
            if(box[i][j]==0) days[i][j] = -1;
            if(box[i][j]==1) push({i,j});
        }
    }
    while(tail!=head){
        pair<int, int> current = front();pop();
        for(int d = 0; d < 4; d++){
            int x = current.first + _x[d];
            int y = current.second + _y[d];
            if(x < 0 || y < 0 || x >= N || y >= M) continue;
            if(days[x][y] >= 0) continue;
            days[x][y] = days[current.first][current.second] + 1;
            push({x,y});
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(days[i][j]==-1){
                cout<<-1;
                return 0;
            }
            answer = max(answer, days[i][j]);
        }
    }
    cout<<answer;
}