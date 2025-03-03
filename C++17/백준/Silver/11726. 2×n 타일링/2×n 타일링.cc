#include <bits/stdc++.h>
using namespace std;

int board[1002];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    board[0] = 1;
    board[1] = 2;
    for(int i = 2; i < n; i++){
        board[i] = (board[i-1]+board[i-2])%10007;
    }

    cout<<board[n-1];
}
