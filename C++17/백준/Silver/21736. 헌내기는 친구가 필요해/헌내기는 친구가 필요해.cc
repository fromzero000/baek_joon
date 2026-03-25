#include <bits/stdc++.h>
using namespace std;

string campus[600];
bool visited[600][600];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    
    cin >> n >> m;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    {
        cin >> campus[i];
        for(int j = 0; j < m; j++)
        {
            if(campus[i][j] == 'I')
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    
    int cnt = 0;
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for(int d = 0; d < 4; d++)
        {
            int nr = cur.first+dr[d];
            int nc = cur.second+dc[d];
            
            if(nr<0||nr>=n||nc<0||nc>=m) continue;
            if(visited[nr][nc]||campus[nr][nc]=='X') continue;
            q.push({nr, nc});
            visited[nr][nc] = 1;
            if(campus[nr][nc]=='P') cnt++;
        }
    }
    if(cnt) cout << cnt;
    else cout << "TT";
}