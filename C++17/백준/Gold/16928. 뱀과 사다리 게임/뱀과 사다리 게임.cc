#include <bits/stdc++.h>
using namespace std;


constexpr int INF = 1e9;
struct state
{
    int pos, cnt;
};

int n, m;
int board[101];
bool visited[101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }
    
    queue<state> q;
    q.push({1, 0});
    visited[1] = 1;
    
    while(!q.empty())
    {
        state cur = q.front();q.pop();
        
        for(int i = 1; i <= 6; i++)
        {
            int next_pos = cur.pos+i;
            if(next_pos > 100) continue;
            if(board[next_pos] != 0)
                next_pos = board[next_pos];
            if(next_pos == 100)
            {
                cout << cur.cnt+1;
                return 0;
            }
            if(!visited[next_pos])
            {
                q.push({next_pos, cur.cnt+1});
                visited[next_pos] = 1;
            }
        }
    }
}