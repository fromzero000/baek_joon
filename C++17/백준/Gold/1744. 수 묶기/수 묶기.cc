#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    priority_queue<int> pos;
    priority_queue<int, vector<int>, greater<int>> neg;
    int zero = 0;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if(t > 0) pos.push(t);
        if(t == 0) zero++;
        if(t < 0) neg.push(t);
    }
    
    int result = 0;
    while(!pos.empty())
    {
        int a = pos.top();pos.pop();
        if(a == 1||pos.empty())
        {
            result += a;
            continue;
        }
        
        int b = pos.top();pos.pop();
        if(b == 1)
        {
            result += a+b;
            continue;
        }
        result += a*b;
    }
    while(!neg.empty())
    {
        int a = neg.top();neg.pop();
        if(neg.empty())
        {
            if(zero > 0) zero--;
            else result += a;
            break;
        }
        int b = neg.top();neg.pop();
        result += a*b;
    }
    
    cout << result;
}