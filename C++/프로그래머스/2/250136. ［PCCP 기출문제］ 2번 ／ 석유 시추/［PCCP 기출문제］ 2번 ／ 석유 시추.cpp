#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <numeric>
using namespace std;


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

queue<pair<int, int>> q;
vector<vector<int>> ground;
vector<vector<bool>> visited;
vector<int> oils;
int id;

int n,m;
void dfs(const vector<vector<int>>& land){
    int answer = 0;
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        answer++;
        for(int i = 0; i < 4; i++){
            auto x = r+dx[i];
            auto y = c+dy[i];
            
            if(x<0||y<0||x>=n||y>=m) continue;
            if(ground[x][y]!=-1||land[x][y]==0) continue;
            ground[x][y] = id;
            q.push({x,y});
        }
    }
    oils.push_back(answer);
    id++;
}
int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    ground = vector<vector<int>>(n,vector<int>(m,-1));
    // visited = vector<vector<bool>>(n,vector<int>(m,false));
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(land[i][j]==1&&ground[i][j]==-1){
                q.push({i,j});
                ground[i][j] = id;
                dfs(land);
            }
        }
    }
    
    for(int col = 0; col < m; col++){
        set<int> line;
        for(int row = 0; row < n; row++){
            int oil_id = ground[row][col];
            if(oil_id!=-1){
                line.insert(oil_id);
            }
        }
        answer = max(answer, accumulate(line.begin(), line.end(),0,[](auto sum, auto i){return sum+oils[i];}));
    }
    return answer;
}