#include <bits/stdc++.h>
using namespace std;

int k;

int len[6];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    for(int i = 0; i < 6; i++)
    {
        int dir;
        cin >> dir >> len[i];
    }
    
    int bigArea = 0;
    int bigIdx =0;
    
    for(int i = 0; i < 6; i++)
    {
        if(bigArea < len[i]*len[(i+1)%6])
        {
            bigArea = len[i]*len[(i+1)%6];
            bigIdx = i;
        }
    }
    int smallArea = len[(bigIdx+3) % 6] * len[(bigIdx + 4) % 6];
    cout << k*(bigArea - smallArea);
}