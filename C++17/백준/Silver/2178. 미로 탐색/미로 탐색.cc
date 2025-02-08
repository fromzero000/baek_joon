#include <bits/stdc++.h>
using namespace std;

string maze[100];
int distances[100][100];
int _x[4] = {0,1,0,-1};
int _y[4] = {1,0,-1,0};

pair<int, int> q[100005];
int head = 0, tail = 0;
void push(pair<int, int> p){
    q[tail++] = p;
}
void pop(){
    head++;
}
pair<int, int> front(){
    return q[head];
}
bool empty(){
    return head==tail;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; i++) fill(distances[i], distances[i]+m, -1);
    for(int i = 0; i < n; i++)
        cin>>maze[i];
    push({0,0});
    distances[0][0] = 0;
    while(!empty()){
        pair<int, int> current = front();
        pop();
        for(int i = 0; i < 4; i++){
            int x = current.first + _x[i];
            int y = current.second + _y[i];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(distances[x][y]>=0||maze[x][y]!='1') continue;
            distances[x][y] = distances[current.first][current.second] + 1;
            push({x,y});
        }
    }
    cout<<distances[n-1][m-1]+1;
}