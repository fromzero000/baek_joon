#include <bits/stdc++.h>
using namespace std;

int sdk[9][9];
vector<pair<int, int>> assignments;

bool possible(int r, int c, int num)
{
  for(int i = 0; i < 9; i++)
  {
    if(sdk[i][c]==num) return 0;
    if(sdk[r][i]==num) return 0;
  }
  int rs = r/3*3, cs = c/3*3;
  for(int i = rs; i < rs+3; i++)
    for(int j = cs; j < cs+3; j++)
      if(sdk[i][j]==num) return 0;

  return 1;
}

bool solve(int cur)
{
  if(cur==assignments.size())
  {
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        cout << sdk[i][j];
      cout << '\n';
    }
    return 1;
  }
  int r = assignments[cur].first, c = assignments[cur].second;

  for(int i = 1; i <= 9; i++)
  {
    if(possible(r,c,i)){
      sdk[r][c] = i;
      if(solve(cur+1)) return 1;
      sdk[r][c] = 0;
    }
  }
  return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    string input;
    for(int i = 0; i < 9; i++)
    {
        cin >> input;
        for(int j = 0; j < 9; j++)
        {
            sdk[i][j] = input[j]-'0';
            if(sdk[i][j]==0) assignments.push_back({i, j});
        }
    }
    
    solve(0);
    
}