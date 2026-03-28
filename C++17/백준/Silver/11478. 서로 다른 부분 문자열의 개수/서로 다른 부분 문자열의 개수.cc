#include <bits/stdc++.h>
using namespace std;


int cnt(const string& s, int len)
{
    set<string> Set;
    for(int i = 0; i <= s.length()-len; i++)
    {
        Set.insert(s.substr(i, len));
    }
    return Set.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int len = s.length(), result = 0;
    for(int i = 1; i <= len; i++)
    {
        result += cnt(s, i);
    }
    cout << result;
}