#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int home[17][17];
//dir 1: 세로, 2: 가로, 3: 대각선

bool possible(pair<int, int> cur, int dir)
{
    int row = cur.first;
    int col = cur.second;
    if(dir==1 || dir==2)
        return (home[row][col]!=1);
    return (home[row-1][col]!=1 && home[row][col-1]!=1 && home[row][col]!=1);
}
void solve(pair<int, int> cur, int dir)
{
    if(cur == make_pair(n, n))
    {
        cnt++;
        return;
    }

    int row = cur.first;
    int col = cur.second;
    if(dir == 1)
    {
        if(row < n)
        {
          if(possible({row+1, col}, 1))
            solve({row+1, col}, 1);
          if(col < n)
            if(possible({row+1, col+1}, 3))
              solve({row+1, col+1}, 3);
        }
        
    }
    
    if(dir == 2)
    {
        if(col < n)
        {
          if(possible({row, col+1}, 2))
            solve({row, col+1}, 2);
          if(row < n)
            if(possible({row+1, col+1}, 3))
              solve({row+1, col+1}, 3);
        }
        
    }
    
    if(dir == 3)
    {
        if(col < n)
          if(possible({row, col+1}, 2))
              solve({row, col+1}, 2);
        if(row < n)
          if(possible({row+1, col}, 1))
              solve({row+1, col}, 1);
        if(col < n && row < n)
        if(possible({row+1, col+1}, 3))
            solve({row+1, col+1}, 3);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> home[i][j];
    
    solve({1, 2}, 2);
    cout << cnt;
}