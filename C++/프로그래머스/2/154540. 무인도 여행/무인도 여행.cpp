#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].length();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maps[i][j] == 'X') continue;
            if(visited[i][j]) continue;
            
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = true;
            int temp = 0;
            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int r = cur.first;
                int c = cur.second;
                temp += maps[r][c]-'0';
                for(int d = 0; d < 4; d++)
                {
                    int nr = r+dr[d];
                    int nc = c+dc[d];
                    
                    if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]) continue;
                    if(maps[nr][nc] == 'X') continue;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            answer.push_back(temp);
        }
    }
    
    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}