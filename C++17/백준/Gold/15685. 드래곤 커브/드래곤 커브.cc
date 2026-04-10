#include <bits/stdc++.h>
using namespace std;

int n;
bool board[101][101];

//방향: 0

struct Point
{
    int x, y;
};
vector<Point> cur;
void createCurve(int g)
{
    if(g <= 0)
    {
        cur.clear();
        return;
    }
    Point st = cur.back();
    for(int i = cur.size()-2; i >= 0; i--)
    {
        int dx = cur[i].x - st.x, dy = cur[i].y - st.y;
        int nx = st.x - dy, ny = st.y + dx;
        board[nx][ny] = true;
        cur.push_back({nx, ny});
    }
    createCurve(g-1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        cur.push_back({x, y});
        board[x][y] = true;
        int nx = x, ny = y;
        switch(d)
        {
            case 0:
                nx++;
                break;
            case 1:
                ny--;
                break;
            case 2:
                nx--;
                break;
            case 3:
                ny++;
        }
        cur.push_back({nx, ny});
        board[nx][ny] = true;
        createCurve(g);
    }
    int result = 0;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 100; j++)
        {
            if(board[i-1][j-1]&&board[i-1][j]&&board[i][j-1]&&board[i][j]) result++;
        }
    }
    cout <<result;
}