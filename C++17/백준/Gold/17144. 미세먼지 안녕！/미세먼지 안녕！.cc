#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int room[50][50];
int temp[50][50];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int ur, uc, lr, lc;
bool upper = 0;

bool isFilter(int r, int c)
{
    return (r==ur&&c==uc)||(r==lr&&c==lc);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> r >> c >> t;
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> room[i][j];
            if(room[i][j] == -1)
            {
                if(upper)
                {
                    lr = i;
                    lc = j;
                }
                else
                {
                    ur = i;
                    uc = j;
                    upper = 1;
                }
            }
        }
    }
    
    while(t--)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                temp[i][j] = room[i][j];
            }
        }
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(room[i][j] <= 0) continue;
                //먼지 발산
                for(int k = 0; k < 4; k++)
                {
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    
                    if(nr<0||nr>=r||nc<0||nc>=c) continue;
                    if(isFilter(nr, nc)) continue;
                    temp[nr][nc] += room[i][j]/5;
                    temp[i][j] -= room[i][j]/5;
                }
            }
        }
        for(int i = ur-1; i >= 1; i--)
                {
                    temp[i][0] = temp[i-1][0];
                }
                for(int i = 0; i < c-1; i++)
                {
                    temp[0][i] = temp[0][i+1];
                }
                for(int i = 0; i < ur; i++)
                {
                    temp[i][c-1] = temp[i+1][c-1];
                }
                for(int i = c-1; i > 0; i--)
                {
                    if(i == 1) temp[ur][i] = 0;
                    else temp[ur][i] = temp[ur][i-1];
                }
                for(int i = lr+1; i < r-1; i++)
                {
                    temp[i][0] = temp[i+1][0];
                }
                for(int i = 0; i < c-1; i++)
                {
                    temp[r-1][i] = temp[r-1][i+1];
                }
                for(int i = r-1; i > lr; i--)
                {
                    temp[i][c-1] = temp[i-1][c-1];
                }
                for(int i = c-1; i > 0; i--)
                {
                    if(i == 1) temp[lr][i] = 0;
                    else temp[lr][i] = temp[lr][i-1];
                }
                for(int i = 0; i < r; i++)
                {
                    for(int j = 0; j < c; j++)
                        room[i][j] = temp[i][j];
                }
    }
    int result{0};
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            if(room[i][j] != -1) result += room[i][j];
    }
    
    cout << result;
}