#include <bits/stdc++.h>
using namespace std;

int n, m;
int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};
int board[500][500];
bool visited[500][500];
int answer = 0;

void iols(int r, int c, int depth, int total)
{
    if(depth == 4)
    {
        answer = max(total, answer);
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        int row = r+dr[i];
        int col = c+dc[i];
        
        if(row<0||col<0||row>=n||col>=m||visited[row][col]) continue;
        visited[row][col] = 1;
        iols(row, col, depth+1, total+board[row][col]);
        visited[row][col] = 0;
    }
}

void t(int r, int c)
{
    priority_queue<int, vector<int>, greater<int>> neighbors;
    for(int i = 0; i < 4; i++)
    {
        int row = r+dr[i];
        int col = c+dc[i];
        
        if(row<0||col<0||row>=n||col>=m) continue;
        neighbors.push(board[row][col]);
    }
    if(neighbors.size() < 3) return;
    int val = board[r][c];
    if(neighbors.size() == 4)
        neighbors.pop();
    while(!neighbors.empty())
    {
        val += neighbors.top();
        neighbors.pop();
    }
    answer = max(answer, val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = 1;
            iols(i, j, 1, board[i][j]);
            visited[i][j] = 0;
            t(i, j);
        }
    }
    
    cout << answer;
}