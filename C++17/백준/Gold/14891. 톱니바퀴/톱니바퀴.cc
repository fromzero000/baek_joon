#include <bits/stdc++.h>
using namespace std;

string gears[5];
deque<char> gear[5];
/*
gears[i][0] : 12시 방향,
gears[i][2] : 3시 방향, 
gears[i][6] : 9시 방향
*/

void rotate(int idx, int dir)
{
    if(dir == 1)
    {
        int t = gear[idx].back();
        gear[idx].pop_back();
        gear[idx].push_front(t);
    }
    else
    {
        int t = gear[idx].front();
        gear[idx].pop_front();
        gear[idx].push_back(t);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= 4; i++) 
        cin >> gears[i];
    
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            gear[i].push_back(gears[i][j]);
        }
    }
    
    int k;
    cin >> k;
    while(k--)
    {
        int idx, dir;
        cin >> idx >> dir;
        int consider[6] = {gear[1][2], gear[2][6], gear[2][2], gear[3][6], gear[3][2], gear[4][6]};
        bool connected[3];
        for(int i = 0; i < 3; i++)
            connected[i] = (consider[i*2] != consider[i*2+1]);
        
        rotate(idx, dir);
        //힘 받는 톱니바퀴 기준 왼쪽
        for(int i = idx-1; i >= 1; i--)
        {
            if(connected[i-1]) rotate(i, dir*pow(-1, idx-i));
            else break;
        }
        //힘 받는 톱니바퀴 기준 오른쪽
        for(int i = idx+1; i <= 4; i++)
        {
            if(connected[i-2]) rotate(i, dir*pow(-1, i-idx));
            else break;
        }
    }
    
    int result = 0;
    
    for(int i = 1; i < 5; i++)
    {
        if(gear[i][0] == '0') continue;
        result += pow(2, i-1);
    }
    
    cout << result;
}