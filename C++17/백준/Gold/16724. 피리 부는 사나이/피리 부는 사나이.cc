#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1001];
int group[1001][1001];
//U D L R
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int cnt = 0;

void dfs(int r, int c)
{
    group[r][c] = -1;
    int nr = r, nc = c;
    switch(board[r][c])
    {
        case 'U':
            nr--;
            break;
        case 'D':
            nr++;
            break;
        case 'L':
            nc--;
            break;
        default:
            nc++;
            break;
    }
    
    if(group[nr][nc] == 0)
        dfs(nr, nc);
    else if(group[nr][nc] == -1)
        cnt++;
    group[r][c] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(group[i][j] == 0)
                dfs(i, j);
        }
    }
    
    cout << cnt;
}