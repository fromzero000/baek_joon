#include <bits/stdc++.h>
using namespace std;

int deg[1001];
vector<int> _next[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    vector<int> result;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int singers;
        cin >> singers;
        
        int prev, following;
        cin >> prev;
        for(int j = 0; j < singers-1; j++)
        {
            cin >> following;
            deg[following]++;
            _next[prev].push_back(following);
            prev = following;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i]==0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int current = q.front();q.pop();
        result.push_back(current);
        for(int& i : _next[current])
        {
            deg[i]--;
            if(deg[i]==0) q.push(i);
        }
    }
    if(result.size()!=n)
    {
        cout << 0;
        return 0;
    }
    for(const int& i : result)
        cout << i <<'\n';
}