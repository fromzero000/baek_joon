#include <bits/stdc++.h>
using namespace std;

int cnt[26];
string name;
string result;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> name;
    for(int i = 0; i <= name.length(); i++)
    {
        cnt[name[i]-'A']++;
    }
    int odd{};
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i]%2 != 0) odd++;
        if(odd > 1)
        {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }
    char center = '0';
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i]%2 == 1)
        {
            center = i+'A';
        }
        for(int j = 0; j < cnt[i]/2; j++)
        {
            result += i+'A';
        }
    }
    string temp = result;
    reverse(temp.begin(), temp.end());
    if(center != '0')
        result += center;
    result += temp;
    cout << result;
}