#include <bits/stdc++.h>
using namespace std;

int r, c;
string board[10000];

bool solve(int row, int col)
{
    if(row<0||row>=r||col<0||col>=c) return false;
    if(board[row][col] == 'x') return false;
    board[row][col] = 'x';
    if(col == c-1) return true;
    if(solve(row-1, col+1)) return true;
    if(solve(row, col+1)) return true ;
    return solve(row+1, col+1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        cin >> board[i];
    
    for(int i = 0; i < r; i++)
        solve(i, 0);
    int result = 0;
    for(int i = 0; i < r; i++)
        if(board[i][c-1]=='x') result++;
    
    cout << result;
}