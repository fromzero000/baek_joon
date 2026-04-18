#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct App
{
    int r, c, s;
};

int dr[] = {0, 0, 1, 0, -1};
int dc[] = {0, 1, 0, -1, 0};

vector<vector<int>> solution(vector<vector<int>> board, vector<vector<int>> commands) {
    int n = board.size();
    int m = board[0].size();
    map<int, App> apps;
    vector<bool> visited(101, false);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int id = board[i][j];
            if(id != 0 && !visited[id])
            {
                visited[id] = true;
                int s = 0;
                while(s+j < m && board[i][s+j] == id) s++;
                apps[id] = {i, j, s};
            }
        }
    }
    auto share_axis = [&](App a1, App a2, int dir)->bool
    {
        if(dir == 1 || dir == 3) return max(a1.r, a2.r) < min(a1.r+a1.s, a2.r+a2.s);
        else return max(a1.c, a2.c) < min(a1.c+a1.s, a2.c+a2.s);
    };
    
    auto get_distance = [&](int a1, int a2, int dir)->int{
        if(dir == 1) return ((((apps[a2].c - (apps[a1].c + apps[a1].s)) % m) + m) % m);
        else if(dir == 2) return ((((apps[a2].r - (apps[a1].r + apps[a1].s)) % n) + n) % n);
        else if(dir == 3) return ((((apps[a1].c - (apps[a2].c + apps[a2].s)) % m) + m) % m);
        else return ((((apps[a1].r - (apps[a2].r + apps[a2].s)) % n) + n) % n);
    };
    
    auto get_real = [&](App cur, int steps, int dir)->int{
        int result = 0;
        for(int step = 1; step <= steps; step++)
        {
            if(dir == 1)
            {
                if (cur.c + cur.s > m - 1) 
                {
                    cur.c = 0; result += cur.s; 
                }
                else
                {
                    cur.c++; result++; 
                }
            }
            if(dir == 2)
            {
                if (cur.r + cur.s > n - 1) 
                {
                    cur.r = 0; result += cur.s; 
                }
                else
                {
                    cur.r++; result++; 
                }
            }
            if(dir == 3)
            {
                if (cur.c < 1) 
                {
                    cur.c = m-cur.s; result += cur.s; 
                }
                else
                {
                    cur.c--; result++; 
                }
            }
            if(dir == 4)
            {
                if (cur.r < 1) 
                {
                    cur.r = n-cur.s; result += cur.s; 
                }
                else
                {
                    cur.r--; result++; 
                }
            }
        }
        return result;
    };
    
    
    auto get_new_pos = [&](App cur, int steps, int dir)->App{
        App next = cur;
        for(int step = 1; step <= steps; step++)
        {
            if (dir == 1) { if (next.c + next.s > m - 1) next.c = 0; else next.c++; }
            else if (dir == 2) { if (next.r + next.s > n - 1) next.r = 0; else next.r++; }
            else if (dir == 3) { if (next.c == 0) next.c = m - next.s; else next.c--; }
            else if (dir == 4) { if (next.r == 0) next.r = n - next.s; else next.r--; }
        }
        return next;
    };
    
    for(const auto& command : commands)
    {
        int id = command[0];
        int dir = command[1];
        if(!visited[id]) continue;
        
        vector<int> moves(101, 0);
        moves[id] = 1;
        
        bool changed = true;
        while(changed)
        {
            changed = false;
            for(int i = 1; i <= 100; i++)
            {
                if(!visited[i]) continue;
                for(int j = 1; j <= 100; j++)
                {
                    if(!visited[j]||i==j) continue;
                    if(share_axis(apps[i], apps[j], dir))
                    {
                        int d_ij = get_distance(i, j, dir);
                        int d_i = get_real(apps[i], moves[i], dir);
                        int d_j = get_real(apps[j], moves[j], dir);
                        
                        if(d_i > d_ij+d_j)
                        {
                            while(get_real(apps[j], moves[j], dir) < d_i - d_ij) moves[j]++;
                            changed = true;
                        }
                        
                    }
                }
            }
        }
        
        for(int i = 1; i <= 100; i++)
        {
            if(!visited[i]||moves[i] == 0) continue;
            App cur = apps[i];
            for(int j = cur.r; j < cur.r+cur.s; j++)
            {
                for(int k = cur.c; k < cur.c+cur.s; k++)
                    board[j][k] = 0;
            }
        }
        
        for(int i = 1; i <= 100; i++)
        {
            if(!visited[i]||moves[i] == 0) continue;
            apps[i] = get_new_pos(apps[i], moves[i], dir);
            App cur = apps[i];
            for(int j = cur.r; j < cur.r+cur.s; j++)
            {
                for(int k = cur.c; k < cur.c+cur.s; k++)
                    board[j][k] = i;
            }
        }
    }
    
    return board;
}