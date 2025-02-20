#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second

int n,m;
int answer;
int office[10][10];
vector<pair<int,int>> points;
vector<int> cctvs;
int calculate(){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(office[i][j] == 0) result++;
        }
    }
    return result;
}

void restart(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) if(office[i][j] == 7) office[i][j] = 0;
    }
}

void rotate(int dir, int idx){
    if(dir == 0){
        for(int j = points[idx].col+1; j < m; j++){
            if(office[points[idx].row][j]==6) break;
            if(office[points[idx].row][j]==0) office[points[idx].row][j] = 7;
            if(office[points[idx].row][j]>0&&office[points[idx].row][j]<6) continue;
        }
    }
    if(dir == 1){
        for(int i = points[idx].row + 1; i < n; i++){
            if(office[i][points[idx].col]==6) break;
            if(office[i][points[idx].col]==0) office[i][points[idx].col] = 7;
            if(office[i][points[idx].col]>0&&office[i][points[idx].col]<6) continue;
        }
    }
    if(dir == 2){
        for(int j = points[idx].col-1; j > -1; j--){
            if(office[points[idx].row][j]==6) break;
            if(office[points[idx].row][j]==0) office[points[idx].row][j] = 7;
            if(office[points[idx].row][j]>0&&office[points[idx].row][j]<6) continue;
        }
    }
    if(dir == 3){
        for(int i = points[idx].row - 1; i > -1; i--){
            if(office[i][points[idx].col]==6) break;
            if(office[i][points[idx].col]==0) office[i][points[idx].col] = 7;
            if(office[i][points[idx].col]>0&&office[i][points[idx].col]<6) continue;
        }
    }
}

void func(int idx){
    int temp[10][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = office[i][j];
        }
    }
    if(idx==cctvs.size()){
        answer = min(answer,calculate());
        return;
       // restart();
    }
    if(cctvs[idx]==1){
        rotate(0,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(2,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(1,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
    }
    if(cctvs[idx]==2){
        rotate(0,idx);rotate(2,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(1,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
    }
    if(cctvs[idx]==3){
        rotate(0,idx);rotate(1,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(2,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(0,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(2,idx);rotate(1,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
    }
    if(cctvs[idx]==4){
        rotate(0,idx);rotate(1,idx);rotate(2,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(1,idx);rotate(2,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(0,idx);rotate(1,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
        rotate(0,idx);rotate(2,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
    }
    if(cctvs[idx]==5){
        rotate(0,idx);rotate(1,idx);rotate(2,idx);rotate(3,idx);
        func(idx+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                office[i][j] = temp[i][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    answer = n*m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>office[i][j];
            if(office[i][j]>0&&office[i][j]<6){
                points.emplace_back(i,j);
                cctvs.push_back(office[i][j]);
            }
        }
    }
    func(0);
    cout<<answer;
}