#include <bits/stdc++.h>
using namespace std;


string str;
char binary[] = {'0', '1'};
int cnt[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;

    char prev = str[0];
    for(int i = 0; i <= str.length(); i++)
    {
        if(prev != str[i])
        {
            cnt[prev-'0']++;
            prev = str[i];
        }
    }
    cnt[prev-'0']++;
    cout << *min_element(cnt, cnt+2);
}