#include <bits/stdc++.h>
using namespace std;

int n;
int maxResult = -1e9, minResult = 1e9;
int op[4]; // add sub mul div
vector<int> nums;

void solve(int idx, int cur)
{
    if(idx == 0)
    {
        solve(1, nums[0]);
        return;
    }
    if(idx == n)
    {
        if(minResult > cur)
            minResult = cur;
        if(maxResult < cur)
            maxResult = cur;
    }
    for(int i = 0; i < 4; i++)
    {
        if(op[i] <= 0) continue;
        op[i]--;
        if(i == 0)
        {
            solve(idx+1, cur+nums[idx]);
            op[i]++;
        }
        if(i == 1)
        {
            solve(idx+1, cur-nums[idx]);
            op[i]++;
        }
        if(i == 2)
        {
            solve(idx+1, cur*nums[idx]);
            op[i]++;
        }
        if(i == 3)
        {
            solve(idx+1, cur/nums[idx]);
            op[i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    
    for(int i = 0; i < 4; i++) cin >> op[i];
    
    solve(0, 0);
    cout << maxResult << '\n' << minResult;
}