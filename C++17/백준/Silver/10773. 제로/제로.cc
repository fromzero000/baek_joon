#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        int cur;
        cin >> cur;
        if(cur==0)
            s.pop();
        else
            s.push(cur);
    }
    int total = 0;
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        total += cur;
    }
    cout << total;
}