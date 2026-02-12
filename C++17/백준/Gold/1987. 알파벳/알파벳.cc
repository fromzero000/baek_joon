#include <bits/stdc++.h>
using namespace std;

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};
int r, c;
string board[20];
bool visited[26];
int score{};

void dfs(pair<int, int> cur, int cnt)
{
    if(cnt > score) score = cnt;
    int row = cur.first, col = cur.second;

    for(int i = 0; i < 4; i++)
    {
        int nr = row+dr[i];
        int nc = col+dc[i];
        if(nr<0||nc<0||nr>=r||nc>=c) continue;
        if(visited[board[nr][nc] - 'A']) continue;
        visited[board[nr][nc] - 'A'] = 1;
        dfs({nr, nc}, cnt+1);
        visited[board[nr][nc] - 'A'] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        cin >> board[i];
    
    visited[board[0][0]-'A'] = 1;
    dfs({0, 0}, 1);
    cout << score;
}