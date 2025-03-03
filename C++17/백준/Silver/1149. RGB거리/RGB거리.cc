#include <bits/stdc++.h>
using namespace std;

int n;

int price[1001][3];// 0 r 1 g 2 b
int sel[1001][3];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cin>>price[i][j];
    }
    for(int i = 0; i < 3; i++){
        sel[0][i] = price[0][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            sel[i][j] = min(sel[i-1][(j+2)%3],sel[i-1][(j+1)%3]) + price[i][j];
        }
    }
    cout<<min({sel[n-1][0],sel[n-1][1],sel[n-1][2]});
}