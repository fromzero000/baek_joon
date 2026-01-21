#include <bits/stdc++.h>
using namespace std;

int n, r, q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> q;
    
    int u, v;
    vector<int> connect[n+1];
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }
    
    vector<int> childs(n+1, 1);
    fill(childs.begin(), childs.end(), 1);
    function<void(int, int)> countChilds = [&](int cur, int p)
    {
        for(const int& i : connect[cur]){
            if(i == p) continue;
            countChilds(i, cur);
            childs[cur] += childs[i];
        }
    };
    
    countChilds(r, 0);
    while(q--)
    {
        cin >> u;
        cout << childs[u] << '\n';
    }
}