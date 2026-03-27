#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    map<string, int> Map;
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        Map[t] = 1;
    }
    
    
    int result = 0;
    for(int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        if(Map.find(t) != Map.end()) result++;
    }
    cout << result;
    
}