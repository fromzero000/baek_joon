#include <bits/stdc++.h>
using namespace std;

int n;

int rgblind, natural;
int visited1[100][100] = {0}; // rgblind
int visited2[100][100] = {0}; // natural

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
char color;
vector<string> board;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    board.resize(n);
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    
    //rgblind
    bool isRG = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited1[i][j]==0){
                if(board[i][j]=='R'||board[i][j]=='G') isRG = 1;
                else isRG = 0;
                color = board[i][j];
                visited1[i][j] = ++rgblind;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    visited1[r][c] = visited1[i][j];
                    for(int d = 0; d < 4; d++){
                        int nr = r+dr[d];
                        int nc = c+dc[d];
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(visited1[nr][nc]!=0) continue;
                        if((isRG&&(board[nr][nc]=='R'||board[nr][nc]=='G'))
                           ||color==board[nr][nc]){
                            q.push({nr, nc});
                            visited1[nr][nc] = visited1[i][j];
                        }
                    }
                }
            }
        }
    }
        
        //natural
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited2[i][j]==0){
                char color = board[i][j];
                visited2[i][j] = ++natural;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for(int d = 0; d < 4; d++){
                        int nr = r+dr[d];
                        int nc = c+dc[d];
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(visited2[nr][nc]!=0) continue;
                        if(board[nr][nc]==color){
                            q.push({nr, nc});
                            visited2[nr][nc] = visited2[i][j];
                        }
                    }
                }
            }
        }
    } 
    
    cout << natural << ' ' << rgblind;
}