#include <bits/stdc++.h>
using namespace std;


bool visited[10000];
int previos[10000];
char cmd[10000];

void bfs(int st, int e)
{
    fill(visited, visited+10000, 0);
    fill(previos, previos+10000, 0);
    fill(cmd, cmd+10000, 0);
    
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if(cur == e)
            break;
        
        int d = cur*2%10000;
        if(!visited[d])
        {
            q.push(d);
            visited[d] = 1;
            previos[d] = cur;
            cmd[d] = 'D';
        }
        int s = (cur+9999)%10000;
        if(!visited[s])
        {
            q.push(s);
            visited[s] = 1;
            previos[s] = cur;
            cmd[s] = 'S';
        }
        int l = cur/1000+cur%1000*10;
        if(!visited[l])
        {
            q.push(l);
            visited[l] = 1;
            previos[l] = cur;
            cmd[l] = 'L';
        }
        int r = cur%10*1000+cur/10;
        if(!visited[r])
        {
            q.push(r);
            visited[r] = 1;
            previos[r] = cur;
            cmd[r] = 'R';
        }
    }
    
    vector<char> result;
    int idx = e;
    
    while(idx!=st)
    {
        result.push_back(cmd[idx]);
        idx = previos[idx];
    }
    for(auto it = result.rbegin(); it != result.rend(); it++)
    {
        cout << *it;
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
}