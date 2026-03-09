#include <bits/stdc++.h>
using namespace std;


int n, m;
int parent[500000];

int findNode(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = findNode(parent[x]);
}

void unionNode(int x, int y)
{
    int nx = findNode(x);
    int ny = findNode(y);
    
    if(nx != ny)
    {
        parent[nx] = ny;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    bool cycle = 0;
    int result = 0;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(findNode(u) == findNode(v))
        {
            cout << i;
            return 0;
        }
        unionNode(u, v);
    }
    cout << 0;
}