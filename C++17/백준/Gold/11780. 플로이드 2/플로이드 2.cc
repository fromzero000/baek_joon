#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = 100001;
int buses[101][101];
int nxt[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
    {
        fill(buses[i]+1, buses[i]+n+1, INF);
        buses[i][i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        if(buses[u][v] > cost) buses[u][v] = cost;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(buses[i][j]!=INF) nxt[i][j] = j;
            else nxt[i][j] = -1;
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(buses[j][i]+buses[i][k] < buses[j][k]) 
                {
                    buses[j][k] = buses[j][i]+buses[i][k];
                    nxt[j][k] = nxt[j][i];
                }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << (buses[i][j] == INF? 0:buses[i][j]) << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j||buses[i][j] == INF)
            {
                cout << 0 << '\n';
                continue;
            }
            int st = i, en = j;
            vector<int> route;
            route.push_back(st);
            while(st != en)
            {
                st = nxt[st][en];
                route.push_back(st);
            }
            cout << route.size() << ' ';
            for(const int& city : route)
                cout << city << ' ';
            cout << '\n';
        }
    }
}