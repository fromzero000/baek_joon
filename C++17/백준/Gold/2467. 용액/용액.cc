#include <bits/stdc++.h>
using namespace std;

int n;
long long solutions[100000];

bool solve(long long a, long long b)
{
    return abs(a) < abs(b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> solutions[i];
    }
    
    int answer1 = 0, answer2 = 0, st = 0, en = n-1;
    long long optimized = 0x7fffffffffffffff;
    while(st < en)
    {
        long long current = solutions[st]+solutions[en];
        if(solve(current, optimized))
        {
            optimized = abs(current);
            answer1 = solutions[st];
            answer2 = solutions[en];
            if(optimized==0) break;
        }
        
        if(current < 0) st++;
        if(current > 0) en--;
    }
    cout << answer1 << ' ' << answer2;
}