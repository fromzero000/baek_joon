#include <bits/stdc++.h>
using namespace std;
int n;
long long divisor = 1e9;
int dp[101][10][1<<10];
int stairNumber(int last, int len, int visited)
{
    if(len == n)
    {
        if(visited == (1<<10)-1) return 1;
        else return 0;
    }
    
    if(dp[len][last][visited] != -1) return dp[len][last][visited];
    
    long long cnt = 0;
    if(last > 0)
    {
        int next = last - 1;
        cnt += stairNumber(next, len+1, visited | (1 << next));
    }
    if(last < 9)
    {
        int next = last + 1;
        cnt += stairNumber(next, len+1, visited | (1 << next));
    }
    return dp[len][last][visited] = cnt % divisor;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    long long answer = 0;
    
    for(int i = 1; i < 10; i++)
    {
        answer += stairNumber(i, 1, (1<<i));
        answer %= divisor;
    }
    
    cout << answer;
}