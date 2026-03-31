#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    if(n == 1)
    {
        int t;
        cin >> t;
        cout << 0;
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> bundles;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        bundles.push(t);
    }
    int result = 0;
    while(bundles.size()!=1)
    {
        int a = bundles.top();bundles.pop();
        int b = bundles.top();bundles.pop();
        result += a+b;
        bundles.push(a+b);
    }
    cout << result;
}