#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<char> lcs(string a, string b)
{
    int alen = a.length();
    int blen = b.length();
    vector<vector<int>> dp(alen+1, vector<int>(blen+1, 0));
    vector<char> result;
    for(int i = 1; i <= alen; i++)
    {
        for(int j = 1; j <= blen; j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    
    int cnt = dp[alen][blen];
    while(alen > 0 && blen > 0)
    {
        if(a[alen-1] == b[blen-1])
        {
            result.push_back(a[alen-1]);
            alen--;
            blen--;
        }
        
        else if(dp[alen-1][blen] >= dp[alen][blen-1])
            alen--;
        else
            blen--;
    }
    return result;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    vector<char> result = lcs(a, b);
    int sz = result.size();
    reverse(result.begin(), result.end());
    cout << sz <<'\n';
    if(sz!=0)
        for(const char& i : result)
            cout << i;
}