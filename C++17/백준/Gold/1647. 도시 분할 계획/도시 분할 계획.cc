#include <bits/stdc++.h>
using namespace std;


struct Edge
{
    int u, v, cost;
    bool operator<(const Edge& other) const
    {
        return this->cost < other.cost;
    }
};
int parent[100001];

int findNode(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = findNode(parent[x]);
}

void unionNode(int a, int b)
{
    a = findNode(a);
    b = findNode(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<Edge> edges(m);
    
    for(int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    int totalCost = 0;
    int maxCost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int cost = edges[i].cost;
        int u = edges[i].u;
        int v = edges[i].v;

        if (findNode(u) != findNode(v))
        {
            unionNode(u, v);
            totalCost += cost;
            maxCost = cost;
        }
    }

    cout << totalCost - maxCost << '\n';
}