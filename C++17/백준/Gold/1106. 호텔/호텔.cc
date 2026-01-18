#include <bits/stdc++.h>
using namespace std;

int c, n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> c >> n;

    int MAX = 1000000;
    vector<int> dp(c+101, MAX);
    dp[0] = 0;
    int cost, people;
    for(int i = 0; i < n; i++)
    {
        cin >> cost >> people;
        
        for(int j = people; j < c+101; j++)
        {
            dp[j] = min(dp[j], dp[j-people]+cost);
        }
    }
    
    int min_cost{MAX};
    for(int i = c; i <= c+100; i++)
        min_cost = min(min_cost, dp[i]);
    
    cout << min_cost;
}