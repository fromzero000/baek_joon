#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int board[101][101];
bool snake[101][101];
deque<pair<int, int>> dq;
bool apples[101][101];
int d = 0;// L: left, D: right

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void nextDir(char c)
{
    if(c == 'L')
        d = (d+3)%4;
    else
        d = (d+1)%4;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        apples[r][c] = true;
    }
    
    cin >> l;
    pair<int, int> pos{1, 1};
    snake[1][1] = true;
    dq.push_back({1, 1});
    int result = 0;
    while(l--)
    {
        int t;
        cin >> t;
        t -= result;
        for(int i = 0; i < t; i++)
        {
            auto cur = dq.back();
            int nr = cur.first+dr[d];
            int nc = cur.second+dc[d];
            if(nr<1||nr>n||nc<1||nc>n||snake[nr][nc])
            {
                cout << result+1;
                return 0;
            }
            if(apples[nr][nc])
                apples[nr][nc] = false;
            else
            {
                auto tail = dq.front();
                snake[tail.first][tail.second] = false;
                dq.pop_front();
            }
            snake[nr][nc] = true;
            dq.push_back({nr, nc});
            result++;
        }
        char c;
        cin >> c;
        nextDir(c);
    }
    
    while(true)
    {
        auto cur = dq.back();
        int nr = cur.first+dr[d];
        int nc = cur.second+dc[d];
        if(nr<1||nr>n||nc<1||nc>n||snake[nr][nc])
        {
            cout << result+1;
            return 0;
        }
        if(apples[nr][nc])
            apples[nr][nc] = false;
        else
        {
            auto tail = dq.front();
            snake[tail.first][tail.second] = false;
            dq.pop_front();
        }
        snake[nr][nc] = true;
        dq.push_back({nr, nc});
        result++;
    }
    cout <<result;
}