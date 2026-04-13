#include <bits/stdc++.h>
using namespace std;

int R, C, M;

struct Shark
{
    //속도, 방향, 크기
    int s, d, z;
};

Shark board[101][101];
Shark temp[101][101];
//1-위, 2-아래, 3-오른, 4-왼
void move(int r, int c, Shark sk)
{
    
    int s = sk.s, d = sk.d, z = sk.z;
    if(d == 1 || d == 2)
    {
        s = s%((R-1)*2);
        for(int i = 0; i < s; i++)
        {
            if(d == 1)
            {
                if(r == 1)
                {
                    d = 2;
                    r = 2;
                }
                else
                {
                    r--;
                }
            }
            else if(d == 2)
            {
                if(r == R)
                {
                    d = 1;
                    r = R-1;
                }
                else r++;
            }
        }
    }
    else if(d == 3 || d == 4)
    {
        s = s%((C-1)*2);
        for(int i = 0; i < s; i++)
        {
            if(d == 4)
            {
                if(c == 1)
                {
                    d = 3;
                    c = 2;
                }
                else
                {
                    c--;
                }
            }
            else if(d == 3)
            {
                if(c == C)
                {
                    d = 4;
                    c = C-1;
                }
                else c++;
            }
        }
    }
    if(temp[r][c].z < sk.z)
        temp[r][c] = {sk.s, d, sk.z};
}

int result = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> M;
    for(int i = 1; i <= M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        board[r][c] = {s, d, z};
    }
    
    int kingPos = 0;
    while(kingPos < C)
    {
        kingPos++;
        /*낚시왕 낚시*/
        for(int i = 1; i <= R; i++)
        {
            if(board[i][kingPos].z)
            {
                result += board[i][kingPos].z;
                board[i][kingPos] = {0, 0, 0};
                break;
            }
        }

        /*상어들 이동*/
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                if(board[i][j].z) move(i, j, board[i][j]);
                board[i][j] = {0, 0, 0};
            }
        }
        
        for(int i = 1; i <= R; i++)
        {
            for(int j = 1; j <= C; j++)
            {
                board[i][j] = temp[i][j];
                temp[i][j] = {0, 0, 0};
            }
        }
    }
    
    cout << result;
}