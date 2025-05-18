#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt, m,n,k,row,col;
    cin>>cnt;
    while(cnt--){
        cin>>m>>n>>k;

        vector<vector<int>> field(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> cabbages;
        for(int i = 0; i < k; i++){
            cin>>col>>row;
            field[row][col] = 1;
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(field[i][j] == 1 && !visited[i][j]){
                    visited[i][j] = 1;
                    cabbages.push({i,j});
                    while(!cabbages.empty()){
                        auto current = cabbages.front(); cabbages.pop();
                        for(auto dir = 0; dir < 4; dir++) {
                            int r = current.first + dx[dir];
                            int c = current.second + dy[dir];
                            if (r < 0 || r > n - 1 || c < 0 || c > m - 1) continue;
                            if (field[r][c] != 1 || visited[r][c] == 1) continue;
                            visited[r][c] = 1;
                            cabbages.push({r, c});
                        }

                    }
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
}