#include <bits/stdc++.h>
using namespace std;


int n;
priority_queue<int, vector<int>, less<int>> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        if(x==0)
            if(!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << 0 << '\n';
        else pq.push(x);
    }
}