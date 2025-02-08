#include <bits/stdc++.h>
using namespace std;
int board[502][502];
bool visited[502][502];
int move_x[4] = {1, 0, -1, 0};
int move_y[4] = {0, 1, 0, -1};
int q[1000005][2];
int head = 0, tail = 0;
void push(int x, int y){
    q[tail][0] = x;
    q[tail++][1] = y;
}
void pop(){
    head++;
}
int* front(){
    return q[head];
}
bool empty(){
    return head == tail;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,num = 0,max = 0;
    cin>>n>>m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>board[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || visited[i][j]) continue;
            num++;
            visited[i][j] = 1;
            push(i,j);
            int area = 0;
            while(!empty()){
                area++;
                int current[2] =  {front()[0], front()[1]};
                pop();
                for(int i = 0; i < 4; i++){
                    int x = current[0] + move_x[i];
                    int y = current[1] + move_y[i];
                    if(x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if(visited[x][y] || board[x][y] != 1) 
                        continue;
                    visited[x][y] = true;
                    push(x,y);
                }
            }
            if(max < area)
                max = area;
        }
    }
    cout<<num<<'\n'<<max;
}