#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> tree[11][11];
int board[11][11];
int fert[11][11];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++)
        fill(board[i]+1, board[i]+n+1, 5);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> fert[i][j];
    
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    
    for(int y = 1; y <= k; y++)
    {
        int deadTrees[11][11];
        for(int i = 0; i <= n; i++)
            fill(deadTrees[i], deadTrees[i]+n+1, -1);
        //봄
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                auto& cur = tree[i][j];
                sort(cur.begin(), cur.end());
                for(int t = 0; t < cur.size(); t++)
                {
                    if(cur[t] <= board[i][j])
                    {
                        board[i][j] -= cur[t];
                        cur[t]++;
                    }
                    else
                    {
                        deadTrees[i][j] = t;
                        break;
                    }
                }
            }
        }
        //여름
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(deadTrees[i][j] != -1)
                {
                    for(int k = deadTrees[i][j]; k < tree[i][j].size(); k++)
                        board[i][j] += tree[i][j][k]/2;
                    tree[i][j].erase(tree[i][j].begin()+deadTrees[i][j], tree[i][j].end());
                }
            }
        }
        //가을
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                auto cur = tree[i][j];
                for(int t = 0; t < cur.size(); t++)
                {
                    if(cur[t]%5 == 0)
                    {
                        for(int r = i-1; r <= i+1; r++)
                        {
                            for(int c = j-1; c <= j+1; c++)
                            {
                                if(r<=0||r>n||c<=0||c>n||r==i&&c==j) continue;
                                tree[r][c].push_back(1);
                            }
                        }
                    }
                }
            }
        }
        //겨울
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                board[i][j] += fert[i][j];
            }
        }
    }
    
    int result = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            result += tree[i][j].size();
    
    cout << result;
}