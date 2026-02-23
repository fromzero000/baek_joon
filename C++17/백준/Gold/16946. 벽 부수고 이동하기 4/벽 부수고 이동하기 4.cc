#include <bits/stdc++.h>
using namespace std;

int n, m;
bool board[1001][1001];
int group[1001][1001];
vector<int> group_size;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        for(int j = 0; j < m; j++)
            board[i][j] = input[j]-'0';
    }
    group_size.push_back(0);
    int id = 1;
    
    queue<pair<int, int>> wallQ;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] || group[i][j] != 0) continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            group[i][j] = id;
            int cnt = 1;
            while(!q.empty())
            {
                auto cur = q.front();q.pop();
                int r = cur.first, c = cur.second;

                for(int d = 0; d < 4; d++)
                {
                    int nr = r+dr[d];
                    int nc = c+dc[d];
                    if(nr<0||nr>=n||nc<0||nc>=m) continue;
                    if(board[nr][nc] == 0 && group[nr][nc] == 0)
                    {
                        cnt++;
                        group[nr][nc] = group[r][c];
                        q.push({nr, nc});
                    }
                }
            }
            group_size.push_back(cnt);
            id++;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!board[i][j])
            {
                cout << '0';
                continue;
            }
            int cnt = 1;
            set<int> s;
            for(int d = 0; d < 4; d++)
            {
                int nr = i+dr[d];
                int nc = j+dc[d];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                if(board[nr][nc]) continue;
                s.insert(group[nr][nc]);
            }
            for(const int& member : s)
                cnt += group_size[member];
            cout << cnt%10;
        }
        cout << '\n';
    }
    
}