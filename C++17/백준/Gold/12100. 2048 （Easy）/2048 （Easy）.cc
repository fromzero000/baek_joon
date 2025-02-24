#include <bits/stdc++.h>
using namespace std;
int board[21][21];
int n, answer = 0;
bool added[21];

void check(){
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) answer = max(answer, board[i][j]);
}
void move(int dir){
//    cout<<dir<<' ';
    if(dir == 0){ // 오른쪽
        for(int i = 0; i < n; i++){
            int cnt = 0;
            fill(added,added+n,0);
            for(int j = n-1; j > -1; j--){
                if(board[i][j] == 0) {
                    cnt++;
                }
                else{
                    if(j+cnt+1<n){
                        if(board[i][j]==board[i][j+cnt+1]){
                            if(!added[j+cnt+1]){
                                board[i][j+cnt+1] *= 2;
                                board[i][j] = 0;
                                added[j+cnt+1] = 1;
                                cnt++;
                            }
                            else{
                                board[i][j+cnt] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                        else if(cnt>0){
                            board[i][j+cnt] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                    else if(cnt>0){
                        board[i][j+cnt] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    if(dir == 1){ // 아랫쪽
        for(int j = 0; j < n; j++){
            int cnt = 0;
            fill(added,added+n,0);
            for(int i = n-1; i > -1; i--){
                if(board[i][j] == 0) {
                    cnt++;
                }
                else{
                    if(i+cnt+1<n){
                        if(board[i][j]==board[i+cnt+1][j]){
                            if(!added[i+cnt+1]){
                                board[i+cnt+1][j] *= 2;
                                board[i][j] = 0;
                                added[i+cnt+1] = 1;
                                cnt++;
                            }
                            else{
                                board[i+cnt][j] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                        else if(cnt>0){
                            board[i+cnt][j] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                    else if(cnt>0){
                        board[i+cnt][j] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    if(dir == 2){ // 왼쪽
        for(int i = 0; i < n; i++){
            int cnt = 0;
            fill(added,added+n,false);
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0) {
                    cnt++;
                }
                else{
                    if(j-cnt-1>-1){
                        if(board[i][j]==board[i][j-cnt-1]){
                            if(!added[j-cnt-1]){
                                board[i][j-cnt-1] *= 2;
                                board[i][j] = 0;
                                added[j-cnt-1] = true;
                                cnt++;
                            }
                            else{
                                board[i][j-cnt] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                        else if(cnt>0){
                            board[i][j-cnt] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                    else if(cnt>0){
                        board[i][j-cnt] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
    if(dir == 3){ // 윗쪽
        for(int j = 0; j < n; j++){
            int cnt = 0;
            fill(added,added+n,0);
            for(int i = 0; i < n; i++){
                if(board[i][j] == 0) {
                    cnt++;
                }
                else{
                    if(i-cnt-1>-1){
                        if(board[i][j]==board[i-cnt-1][j]){
                            if(!added[i-cnt-1]){
                                board[i-cnt-1][j] *= 2;
                                board[i][j] = 0;
                                added[i-cnt-1] = 1;
                                cnt++;
                            }
                            else{
                                board[i-cnt][j] = board[i][j];
                                board[i][j] = 0;
                            }
                        }
                        else if(cnt>0){
                            board[i-cnt][j] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                    else if(cnt>0){
                        board[i-cnt][j] = board[i][j];
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout<<board[i][j]<<' ';
//        }cout<<'\n';
//    }cout<<'\n';
}
void func(int k){
    if(k==5){
        check();
//        cout<<answer<<'\n';
        return;
    }
    int temp[n+1][n+1];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) temp[i][j] = board[i][j];
    move(0);
    func(k+1);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = temp[i][j];
    move(1);
    func(k+1);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = temp[i][j];
    move(2);
    func(k+1);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = temp[i][j];
    move(3);
    func(k+1);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) board[i][j] = temp[i][j];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
//    move(1);
//    move(0);
//    move(1);
//    move(1);
//    move(2);
    func(0);

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cout<<board[i][j]<<' ';
//        }cout<<'\n';
//    }cout<<'\n';
    cout<<answer;
}
