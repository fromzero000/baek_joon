#include <string>
#include <vector>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();
    pair<int, int> s, l, e;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maps[i][j] == 'S')
                s = {i, j};
            if(maps[i][j] == 'L')
                l = {i, j};
            if(maps[i][j] == 'E')
                e = {i, j};
        }
    }
    
    auto move = [&](pair<int, int> dest)->int{
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        q.push(s);
        
        while(!q.empty())
        {
            auto cur = q.front();q.pop();
            int r = cur.first, c = cur.second;
            
            for(int d = 0; d < 4; d++)
            {
                int nr = r+dr[d];
                int nc = c+dc[d];
                if(nr<0||nr>=n||nc<0||nc>=m||maps[nr][nc]=='X'||dist[nr][nc]!=-1) continue;
                if(nr == dest.first && nc == dest.second) return dist[r][c]+1;
                dist[nr][nc] = dist[r][c]+1;
                q.push({nr, nc});
            }
        }
        
        return -1;
    };
    int toLever = move(l);
    if(toLever == -1)
        return -1;
    s = l;
    int toEntrance = move(e);
    if(toEntrance == -1)
        return -1;
    return toLever+toEntrance+2;
}