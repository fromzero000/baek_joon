#include <bits/stdc++.h>
using namespace std;



constexpr int INF = 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> cnt[26];
        string s;
        int n;
        cin >> s >> n;

        for(int i = 0; i < s.length(); i++)
            cnt[s[i]-'a'].push_back(i);
        int shortest = INF, longest = -1;
        for(const vector<int>& v : cnt)
        {
            if(v.size()>=n)
            {
                for(int i = 0; i < v.size(); i++)
                {
                    if(i+n-1 < v.size())
                    {
                        shortest = min(shortest, v[i+n-1]-v[i]+1);
                        longest = max(longest, v[i+n-1]-v[i]+1);
                    }
                }
            }
        }
        if(shortest == INF) cout << -1;
        else cout << shortest << ' ' << longest;
        cout << '\n';
    }
}