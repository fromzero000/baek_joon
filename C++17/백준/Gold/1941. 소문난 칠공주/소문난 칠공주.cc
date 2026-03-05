#include <bits/stdc++.h>
using namespace std;

vector<string> room(5);
int result;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++){
        cin >> room[i];
    }
    
    vector<int> combination(25, 0);
    for(int i = 18; i < 25; i++) combination[i] = 1;
    do{
        int scnt = 0;
        int st = -1, en = -1;
        queue<pair<int, int>> q;
        for(int i = 0; i < 25; i++){
            if(combination[i]==1){
                int r = i/5;
                int c = i%5;
                if(room[r][c] == 'S'){
                    scnt++;
                }
                st = r;
                en = c;
            }
        }
        if(scnt >= 4){
            queue<pair<int, int>> q;
            bool visited[5][5] = {0};
            q.push({st, en});
            visited[st][en] = 1;
            int connect_cnt = 0;
            while(!q.empty()){
                pair<int, int> cur = q.front(); q.pop();
                connect_cnt++;
                
                for(int i = 0; i < 4; i++){
                    int nr = cur.first+dr[i];
                    int nc = cur.second+dc[i];
                    
                    if(nr<0||nr>=5||nc<0||nc>=5) continue;
                    if(visited[nr][nc]) continue;
                    
                    if(combination[nr*5+nc] == 1){
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            if(connect_cnt == 7) result++;
        }
        
    }while(next_permutation(combination.begin(), combination.end()));
    
    cout << result;
}