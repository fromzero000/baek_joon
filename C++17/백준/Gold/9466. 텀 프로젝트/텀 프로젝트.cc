#include <bits/stdc++.h>
using namespace std;

int arr[100001];
bool visited[100001];
bool done[100001];
int cnt;
void dfs(int current)
{
    visited[current] = 1;
    int next = arr[current];
    
    if(!visited[next])
        dfs(next);
    else if(!done[next])
    {
        for(int i = next; i != current; i = arr[i])
            cnt++;
        cnt++;
    }
    done[current] = 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;
    
    while(t--)
    {
        cin >> n;        
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            visited[i] = 0;
            done[i] = 0;
        }
        cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!visited[i])
                dfs(i);
        }
        cout << n - cnt << '\n';
    }
}