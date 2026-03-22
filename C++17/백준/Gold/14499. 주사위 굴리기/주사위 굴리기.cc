#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int board[20][20];
//위 아래 남 북 서 동
int dice[] = {0, 0, 0, 0, 0, 0};
int dr[] = {0, 0, 0, -1, 1}; //동서북남
int dc[] = {0, 1, -1, 0, 0};

void Roll(int d)
{
    int temp[6];
    for(int i = 0; i < 6; i++)
        temp[i] = dice[i];
    switch(d)
    {
        case 1:
            dice[0] = temp[4];
            dice[5] = temp[0];
            dice[1] = temp[5];
            dice[4] = temp[1];
            break;
        case 2:
            dice[0] = temp[5];
            dice[4] = temp[0];
            dice[1] = temp[4];
            dice[5] = temp[1];
            break;
        case 3:
            dice[0] = temp[2];
            dice[3] = temp[0];
            dice[1] = temp[3];
            dice[2] = temp[1];
            break;
        default:
            dice[0] = temp[3];
            dice[3] = temp[1];
            dice[1] = temp[2];
            dice[2] = temp[0];
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    while(k--)
    {
        int d;
        cin >> d;
        int nr = x+dr[d];
        int nc = y+dc[d];
        if(nr<0||nr>=n||nc<0||nc>=m) continue;
        
        x = nr, y = nc;
        Roll(d);
        if(board[x][y] == 0)
            board[x][y] = dice[1];
        else
        {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }
        
        cout << dice[0] << '\n';
    }
}