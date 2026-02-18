#include <bits/stdc++.h>
using namespace std;


int n, m;

int pool[50][50];
bool visited[50][50];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};


int bfs(int r, int c, int height)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    int cnt{1};
    bool isLeak = 0;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();q.pop();
        
        for(int d{0}; d < 4; d++)
        {
            int nr{cur.first+dr[d]};
            int nc{cur.second+dc[d]};
            if(nr<0||nr>n-1||nc<0||nc>m-1)
            {
                isLeak = 1;
                continue;
            }
            if(visited[nr][nc]) continue;
            if(pool[nr][nc]<height)
            {
                visited[nr][nc] = 1;
                q.push({nr, nc});
                cnt++;
            }
            
        }
    }
    return (isLeak?0:cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < m; j++)
            pool[i][j] = input[j] - '0';
    }
    int result{0};
    queue<pair<int, int>> q;
    for(int h = 1; h <= 9; h++)
    {
        for(int i = 0; i < n; i++) fill(visited[i], visited[i]+m, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pool[i][j] < h && !visited[i][j])
                    result += bfs(i, j, h);
            }
        }
    }
    
    cout << result;
}