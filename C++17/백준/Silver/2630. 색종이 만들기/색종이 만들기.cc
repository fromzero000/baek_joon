#include <bits/stdc++.h>
using namespace std;


int blue{};
int white{};
bool paper[128][128];

bool is_completed(int row, int col, int len){
    bool color = paper[row][col];

    for(int i = row; i < row+len; i++){
        for(int j = col; j < col+len; j++){
            if(paper[i][j]!=color) {
                is_completed(row, col, len/2);
                is_completed(row+len/2, col, len/2);
                is_completed(row, col+len/2, len/2);
                is_completed(row+len/2, col+len/2, len/2);
                return false;
            }
        }
    }
  
    if(color) blue++;
    else white++;
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    bool color;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> color;
            paper[i][j] = color;
        }
    }
    is_completed(0,0,N);
    cout<<white<<'\n'<<blue;
}