#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[50][50];
//0 북 1 동 2 남 3 서

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int r, c, dir;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> r >> c >> dir;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int result = 0;
    
    while(true)
    {
        if(board[r][c] == 0)
        {
            board[r][c] = 2;
            result++;
        }
        bool next = false;
        for(int i = 0; i < 4; i++)
        {
            dir = (dir+3)%4;
            int nr = r+dr[dir];
            int nc = c+dc[dir];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==0)
            {
                r = nr;
                c = nc;
                next = true;
                break;
            }
        }
        
        if(!next)
        {
            int backdir = (dir+2)%4;
            int backr = r+dr[backdir];
            int backc = c+dc[backdir];
            if(backr>=0 && backr<n && backc>=0 && backc<m && board[backr][backc] != 1)
            {
                r = backr;
                c = backc;
            }
            else
                break;
        }
    }
    
    cout << result;
}