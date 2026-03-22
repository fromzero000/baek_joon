#include <bits/stdc++.h>
using namespace std;

int n;
int board[100][100];
int result[101];
int maxHeight = 0;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};


void solve(int depth)
{
    vector<vector<bool>> visited(n, vector<bool>(n));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] > depth && visited[i][j] == 0)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                
                while(!q.empty())
                {
                    auto cur = q.front();q.pop();
                    for(int d = 0; d < 4; d++)
                    {
                        int nr = cur.first+dr[d];
                        int nc = cur.second+dc[d];
                        if(nr<0||nr>=n||nc<0||nc>=n) continue;
                        if(visited[nr][nc]) continue;
                        if(board[nr][nc] > depth)
                        {
                            visited[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                    }
                }
                result[depth]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if(board[i][j] > maxHeight)
                maxHeight = board[i][j];
        }
    }
    
    for(int i = 0; i < maxHeight; i++)
    {
        solve(i);
    }
    
    cout << *max_element(result, result+maxHeight+1);
}