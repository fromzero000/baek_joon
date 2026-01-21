#include <bits/stdc++.h>
using namespace std;

int n, m;
int nums[9];
//n=5, m=3, idx=0 1 2 3 4 5
void printNums()
{
  for(int i = 1; i <= m; i++)
    cout<<nums[i]<<' ';
  cout<<'\n';
}
void solve(int idx)
{
  if(idx==m+1){
    printNums();
    return;
  }

  for(int i = nums[idx-1]; i <= n; i++)
    {
      nums[idx] = i;
      solve(idx+1);
    }
}
        
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;nums[0]=1;
    solve(1);
}