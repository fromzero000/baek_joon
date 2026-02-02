#include <bits/stdc++.h>
using namespace std;

#define row first
#define col second
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
string board[25];
bool visited[25][25];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> results;
    
    for(int i = 0; i < n; i++)
        cin >> board[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && board[i][j] == '1')
            {
                int cnt = 0;
                stack<pair<int, int>> s;
                s.push(make_pair(i, j));
                while(!s.empty())
                {
                    pair<int, int> cur = s.top();
                    s.pop();
                    if(visited[cur.row][cur.col]) continue;
                    cnt++;
                    visited[cur.row][cur.col] = 1;
                    for(int d = 0; d < 4; d++)
                    {
                        int r = cur.row+dr[d];
                        int c = cur.col+dc[d];
                        
                        
                        if(r<0||r>=n||c<0||c>=n) continue;
                        if(board[r][c]=='1')
                        {
                            s.push(make_pair(r, c));
                        }                            
                    }
                }
                results.push_back(cnt);
            }
        }
    }
    sort(results.begin(), results.end());
    
    cout << results.size() << '\n';
    for(const int& i : results)
        cout << i << '\n';
}