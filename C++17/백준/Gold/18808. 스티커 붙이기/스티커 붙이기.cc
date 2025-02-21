#include <bits/stdc++.h>
using namespace std;

int laptop[42][42];
int sticker[12][12];
int n,m,k,r,c;

void rotate(){
    int temp[12][12];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            temp[j][r-i-1] = sticker[i][j];
        }
    }
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            sticker[i][j] = temp[i][j];
        }
    }
    int t = c;
    c = r;
    r = t;
}

bool func(int row, int col){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(laptop[row+i][col+j]==1&&sticker[i][j]==1) return false;
        }
    }
    return true;
}

void paste(int row, int col){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j]==1) laptop[row+i][col+j] = 1;
        }
    }
}

int calculate(){
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(laptop[i][j] == 1) answer++;
        }
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;

    for(int i = 0; i < k; i++){
        cin>>r>>c;
        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                cin>>sticker[x][y];
            }
        }

        for(int t = 0; t < 4; t++){
            for(int row = 0; row < n - r + 1 && t < 4; row++){
                for(int col = 0; col < m - c + 1 && t < 4; col++){
                    if(func(row, col)) {
                        paste(row, col);
                        t = 4;
                    }
                }
            }
            rotate();
        }
    }
    cout<<calculate();
}