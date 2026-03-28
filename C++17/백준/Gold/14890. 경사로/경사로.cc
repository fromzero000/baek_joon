#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int result = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    
    //row
    for(int i = 0; i < n; i++)
    {
        bool road = true;
        int cnt = 1;
        int prev = board[i][0];
        int slope = 0;
        int plain = 1;
        while(road && cnt < n)
        {
            int diff = board[i][cnt] - prev;
            if(diff > 0)
            {
                if(diff > 1 || plain < l)
                {
                    road = false;
                    break;
                }
                else plain = 1;
            }
            else if(diff < 0)
            {
                if(diff < -1 || cnt+l > n)
                {
                    road = false;
                    break;
                }
                slope = l;
                for(int j = cnt+1; j < cnt+l; j++)
                {
                    if(board[i][j] != board[i][cnt])
                    {
                        road = false;
                        break;
                    }
                }
                plain = 0;
                cnt += l-1;
            }
            else
            {
                plain++;
            }
            prev = board[i][cnt];
            cnt++;
        }
        if(road) result++;
    }
    
    //col
    for(int i = 0; i < n; i++)
    {
        bool road = true;
        int cnt = 1;
        int prev = board[0][i];
        int slope = 0;
        int plain = 1;
        while(road && cnt < n)
        {
            int diff = board[cnt][i] - prev;
            if(diff > 0)
            {
                if(diff > 1 || plain < l)
                {
                    road = false;
                    break;
                }
                else plain = 1;
            }
            else if(diff < 0)
            {
                if(diff < -1 || cnt+l > n)
                {
                    road = false;
                    break;
                }
                slope = l;
                for(int j = cnt+1; j < cnt+l; j++)
                {
                    if(board[j][i] != board[cnt][i])
                    {
                        road = false;
                        break;
                    }
                }
                plain = 0;
                cnt += l-1;
            }
            else
            {
                plain++;
            }
            prev = board[cnt][i];
            cnt++;
        }
        if(road) result++;
    }
    
    cout << result;
}