#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int items[101];
int total[101];
int road[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> items[i];
    }
    
    for(int i = 1; i <= n; i++)
    {
        fill(road[i]+1, road[i]+n+1,16);
        road[i][i] = 0;
    }
    
    for(int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        road[a][b] = road[b][a] = l;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                road[j][k] = min(road[j][k], road[j][i]+road[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(road[i][j] <= m) total[i] += items[j];
        }
    }
    
    cout << *max_element(total+1, items+n);
}